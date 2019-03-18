/*
This tutorial is taken from 
https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/display_image.html
And modified accoridingly
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (!image.data) {
        cout << "Could not open/find image" << '\n';
        return -1;
    }

    namedWindow("DisplayWindow", WINDOW_AUTOSIZE);
    imshow("DisplayWindow", image);

    waitKey(0);
    return 0;

}
