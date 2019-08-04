#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char const *argv[])
{
    if ( argc != 2)
    {
        printf("usage: DisplayImage.out<Image_Path>\n");
        return -1;
    }
    
    char *imgName = (char*)argv[1];
    Mat image;
    image = imread(imgName, IMREAD_COLOR);
    
    if (!image.data)
    {
        printf("no image data! \n");
        return -1;
    }

    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    imwrite("./Gray_Image.jpg", gray_image);

    namedWindow(imgName, WINDOW_AUTOSIZE);
    namedWindow("Gray image", WINDOW_AUTOSIZE);

    imshow(imgName, image);
    imshow("Gray image", gray_image);
    
    waitKey(0);

   return 0;
}
