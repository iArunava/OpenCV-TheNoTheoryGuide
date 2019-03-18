/*
This tutorial is taken from 
https://docs.opencv.org/2.4/doc/tutorials/introduction/core/
And modified accoridingly
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void print_mat(Mat m, char f='p') {
    cout << "The Size of the Matrix: " << endl << " " << m.size() << endl << endl;
    cout << "The Type of the matrix: " << typeid(m).name() << "\n";

    if (f == 'd')
        cout << "The Matrix: " << endl << " " << m << endl << endl;
    else if (f == 'p')
        cout << "The Matrix: " << endl << " " << format(m, 3) << endl << endl;
    else if (f == 'n')
        cout << "The Matrix: " << endl << " " << format(m, 4) << endl << endl;
    else if (f == 'v')
        cout << "The Matrix: " << endl << " " << format(m, 2) << endl << endl;
    else if (f == 'c')
        cout << "The Matrix: " << endl << " " << format(m, 1) << endl << endl;
}
    
int main(int argc, char** argv) {
    // Mat Constructor
    // CV_[The number of bits per item][Signed or Unsigned][Type Pref][# of channels]
    Mat M1(2, 2, CV_8UC3, Scalar(0, 0, 255));
    print_mat (M1);
    
    int sz[] = {2, 2, 2};
    //cv::Mat L(3, sz, CV_8U, Scalar::all(0));
    //print_mat (M);
    
    //  Convert PIL Image to Mat
    IplImage* img = cvLoadImage("new_image.png", 1);
    cout << typeid(img).name() << "\n";
    Mat m = cv::cvarrToMat(img); // Convert IplImage* -> Mat
    cout << typeid(m).name() << "\n";
    
    // Create() function
    Mat M2;
    M2.create(4, 4, CV_8UC(2));
    print_mat (M2);
    
    // Zeros, ones, eye
    Mat e1 = Mat::eye(3, 3, CV_64F);
    print_mat(e1);

    Mat o1 = Mat::ones(3, 3, CV_64F);
    print_mat(o1);

    Mat z1 = Mat::zeros(3, 3, CV_64F);
    print_mat(z1);

    // Small Matrices
    Mat smat = (Mat_<double>(3, 3) << 0, -1, 0, -1, 34, 12, 4, 6);
    print_mat(smat);
    
    // Take the row
    Mat r1 = smat.row(1).clone();
    Mat r2 = smat.row(2).clone();
    Mat c1 = smat.col(1).clone();
    Mat c2 = smat.col(2).clone();
    print_mat(r1); print_mat(r2); print_mat(c1); print_mat(c2); 

    // Fill out Random values
    Mat R = Mat(3, 2, CV_8UC3);
    cv::randu(R, cv::Scalar::all(0), cv::Scalar::all(255));
    print_mat(R);
    
    // 2D Point
    Point2f P(5, 1);
    cout << "Point (2D) = " << P << endl << endl;

    // 3D Point
    Point3f P3f(2, 6, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    //std::vector via cv::Mat
    std::vector<float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

    // std::vector of points
    vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); ++i)
        vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    cout << "A vector of 2d points: " << format(vPoints, 3) << endl << endl;

    return 0;
}
