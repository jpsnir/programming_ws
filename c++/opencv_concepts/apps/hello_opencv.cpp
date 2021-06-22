//
// Created by jagatpreet on 2/22/21.
//
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv){
    cout<<"number of arguments = "<<argc<<endl;
    cout<<"image name = "<<argv[1]<<endl;
    String imageName("/media/jagatpreet/Data/datasets/concepts/jetyak.png");
    if (argc > 1)
        imageName = argv[1];

    Mat imageData;
    imageData = imread(imageName,IMREAD_GRAYSCALE);
    if (imageData.empty()) {
        cout<< "file not found"<<endl;
        return -1;
    }// if invalid input
    namedWindow("Display Window",CV_WINDOW_AUTOSIZE);
    imshow("Display Window",imageData);
    waitKey(0);
    exit(0);
}