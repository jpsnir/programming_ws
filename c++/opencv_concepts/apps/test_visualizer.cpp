//
// Created by jagatpreet on 3/3/21.
//

#include "../include/Visualizer.h"
#include <iostream>
#include <vector>
#include <unistd.h>

int rows,cols;
array<Scalar,3> colors;
list<Point> keypoints;
Mat image;
string name;
void Initialize();
list<Point> PredictPoints(list<Point> kpts,int pixels);
void Initialize(){
    name = "testing visualizer";
    cols = 640;
    rows = 512;
    colors = {Scalar{0,0,255},
                              Scalar{0,255,255},
                              Scalar{255,255,255}};

    // Define dummy list of keypoints
    float factor[] = {1.0/8,2.0/8,3.0/8,4.0/8,5.0/8,6.0/8,7.0/8};
    int size = sizeof(factor)/sizeof(float);
    Mat_<Point> mat_keypoints(size,size);
    for (int i = 0; i < mat_keypoints.rows; i++)
        for(int j = 0; j < mat_keypoints.cols; j++)
            mat_keypoints.at<Point>(i,j) = Point2d(factor[i]*rows,factor[j]*cols);

    for (auto it = mat_keypoints.begin();it!=mat_keypoints.end();it++)
        keypoints.push_back(*it);
    image = Mat::zeros(cols,rows,CV_8UC3);
}

list<Point> PredictPoints(list<Point> kpts, int pixels){
    list<Point> predictedPoints;
    if (kpts.size()==0)
        cout<<"Input empty"<<endl;
    for(auto it = kpts.begin();it!=kpts.end();it++)
        predictedPoints.push_back(*it+Point(pixels,pixels));
    return predictedPoints;
}

int main(int argc, char **argv )
{

    // Initialize variables
    Initialize();

    // Define visualizer parameters
    Visualizer dummyVisualizer(name,image);
    dummyVisualizer.rows = rows;
    dummyVisualizer.cols = cols;
    dummyVisualizer.SetElementColor(colors);
    dummyVisualizer.visualizer_markers.pointMarker = MARKER_STAR;
    dummyVisualizer.visualizer_markers.keypointMarker = MARKER_TILTED_CROSS;
    dummyVisualizer.visualizer_size.sizeKeypointMarker = 12;
    dummyVisualizer.visualizer_size.sizePointMarker = 5;
    dummyVisualizer.kp_list = keypoints;
    dummyVisualizer.ShowPoints(keypoints,keypoint);
    for(int i = 0; i<100;i++){
        list<Point> predictPoints = PredictPoints(keypoints,1+i*10/20);
        if(i%10==0)
            dummyVisualizer.ShowPoints(predictPoints,keypoint);
        else
            //dummyVisualizer.ShowPoints(predictPoints,predicted);
        usleep(100);
    }
    // show in window
    imshow( name, image );
    moveWindow( name, 0, 200 );
    waitKey( 0 );
    return(0);
}