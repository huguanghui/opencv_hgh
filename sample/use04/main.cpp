#include <opencv2/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char const *argv[])
{
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;

    M.create(4,4, CV_8UC(2));
    cout << "M = " << endl << " " << M << endl << endl;

    int sz[3] = {2,2,2};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));

    Mat E = Mat::eye(4, 4, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;

    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;

    Mat Z = Mat::zeros(3, 3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

    Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl << endl;

    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;

    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));

    cout << "R (default) = " << endl << endl << R << endl << endl;
    cout << "R (python) = " << endl << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;
    cout << "R (numpy) = " << endl << endl << format(R, Formatter::FMT_NUMPY) << endl << endl;
    cout << "R (csv) = " << endl << endl << format(R, Formatter::FMT_CSV) << endl << endl;
    cout << "R (c) = " << endl << endl << format(R, Formatter::FMT_C) << endl << endl;

    Point2f P(5, 1);
    cout << "Point (2D) = " << P << endl << endl;

    Point3f P3f(2, 6, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    vector<float> v;
    v.push_back( (float)CV_PI);
    v.push_back(2);
    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

    vector<Point2f> vPoints(20);
    for (size_t  i = 0; i < vPoints.size(); ++i)
    {
        vPoints[i] = Point2f((float)(i*5), (float)(i % 7));
    }
    cout << "A vector of 2D Points = " << format(vPoints, Formatter::FMT_PYTHON) << endl << endl;

    return 0;
}
