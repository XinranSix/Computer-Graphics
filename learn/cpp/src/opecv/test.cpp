//
// Created by yaojie on 2023/5/12.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

void trackBar(int, void *);
int s1 = 0, s2 = 0;
Mat src, dst;
int main() {
    src = imread("D:/Computer-Graphics/images/title/eva/829601.png");
    if (src.empty()) {
        printf("can not load image \n");
        return -1;
    }
    namedWindow("input");
    imshow("input", src);
    dst = src.clone();
    namedWindow("output");
    createTrackbar("canny1", "output", &s1, 255, trackBar);
    createTrackbar("canny2", "output", &s2, 255, trackBar);
    GaussianBlur(src, src, Size(3, 3), 0);

    waitKey();
    return 0;
}

void trackBar(int, void *) {
    Canny(src, dst, s1, s2, 3);
    imshow("output", dst);
}