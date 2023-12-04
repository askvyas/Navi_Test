// https://www.geeksforgeeks.org/opencv-c-plus-plus-program-to-play-a-video/
// #include "opencv2/highgui/highgui.hpp"
// #include<iostream>
// using namespace cv;
// using namespace std;
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap("../backend/uploads/robot_video_2023-11-21_16-09-38.avi");
    if (!cap.isOpened()) {
        cout << "Cannot open the video file.\n";
        return -1;
    }

    double fps = cap.get(cv::CAP_PROP_FPS);

    namedWindow("Video Window", cv::WINDOW_AUTOSIZE);
    while (1) {
        Mat frame;

        if (!cap.read(frame)) {
            cout << "\n Cannot read the video file.\n";
            break;
        }

        imshow("A_good_name", frame);

        if (waitKey(30) == 27) {
            break;
        }
    }

    return 0;
}
