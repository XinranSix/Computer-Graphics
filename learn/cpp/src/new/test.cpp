//
// Created by yaojie on 2023/5/12.
//

#include <opencv2\opencv.hpp>
#include <string>
using namespace cv;
using namespace std;

int main() {
    // 读取视频或摄像头
    VideoCapture capture(0);

    while (true) {
        Mat frame;
        capture >> frame;
        imshow(std::string{"读取视频"}, frame);
        waitKey(60); // 延时30
    }
    return 0;
}