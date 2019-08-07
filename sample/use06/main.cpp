/**
 * @file LinearBlend.cpp
 * @brief Simple linear blender ( dst = alpha*src1 + beta*src2 )
 * @author OpenCV team
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

/** Global Variables */
const int alpha_max = 5;
const int beta_max = 125;
int alpha;
int  beta;

/** Matrices to store images */
Mat image;

/**
 * @function on_trackbar
 * @brief trackbar 的回调函数
 */
static void on_trackbar( int, void* )
{
    Mat  new_image = Mat::zeros( image.size(), image.type());

    for ( int y = 0; y < image.rows; y++)
    {
        for ( int x = 0; x < image.cols; x++)
        {
            for ( int c = 0; c < 3; c++)
            {
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*(image.at<Vec3b>(y,x)[c] ) + beta );
            }
        }
    }
    imshow("New Image", new_image);
}

/**
 * @function main
 * @brief 主函数
 */
int main(int argc, char *argv[])
{
    /// 读取指定图片
    String imageName("./data/lena.jpg");
    if (argc > 1)
    {
        imageName = argv[1];
    }
    image = imread(imageName);

    /// 初始化参数
    alpha = 1;
    beta = 0;

    /// 创建 Windows 窗口
    namedWindow("Origin Image", 1);
    namedWindow("New Image", 1);

    /// 创建 trackbar
    createTrackbar("Contrast", "New Image", &alpha, alpha_max, on_trackbar);
    createTrackbar("Brightness", "New Image", &beta, beta_max, on_trackbar);

    /// 显示
    imshow("Origin Image", image);
    imshow("New Image", image);

   /// Wait until user press some key
   waitKey(0);
   return 0;
}
