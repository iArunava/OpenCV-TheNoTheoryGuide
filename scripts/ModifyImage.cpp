/*
This tutorial is taken from 
https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/
And modified accoridingly
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    
    char* imageName = argv[1];

    Mat image;
    image = imread(imageName, 1);

    if (argc != 2 || !image.data) {
        printf("No image data \n");
        return -1;
    }

    Mat gray_image;
    cvtColor(image, gray_image, CV_BGR2GRAY);

    imwrite("new_image.png", gray_image);

    namedWindow(imageName, CV_WINDOW_AUTOSIZE);
    namedWindow("gray_image", CV_WINDOW_AUTOSIZE);

    imshow(imageName, image);
    imshow("gray_image", gray_image);

    waitKey(0);

    return 0;
}
