#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    double alpha = 0.5;
    double beta;
    double input;
    Mat src1;
    Mat src2;
    Mat dst;
   
    // 1.设置参数
    cout << "Please Input [0.0-1.0]:" << endl;
    cin >> input;
    if (input >=0 && input <= 1)
    {
        alpha = input;
    }

    // 2.加载图片
    src1 = imread("./data/LinuxLogo.jpg");
    src2 = imread("./data/WindowsLogo.jpg");

    if (src1.empty())
    {
        cout << "Load Image Err!" << endl;
        return -1;
    }

    if (src2.empty())
    {
        cout << "Load Image Err!" << endl;
        return -1;
    }
    
    // 3.线性混合
    beta = 1 - alpha;
    addWeighted(src1, alpha, src2, beta, 0.0, dst);

    // 4.显示混合后的图片
    imshow("Linear Blender", dst); 
    waitKey(0);

   return 0;
}
