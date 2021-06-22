//
// Created by jagatpreet on 3/3/21.
//

#ifndef C__PROGRAMS_VISUALIZER_H
#define C__PROGRAMS_VISUALIZER_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <list>
#include <map>
#include <string>

using namespace cv;
using namespace std;

enum color{red,green,blue,white};
struct ElementColors{
    Scalar markerColor;
    Scalar lineColor;
    Scalar pointColor;
};

struct ElementMarkers{
    MarkerTypes pointMarker;
    MarkerTypes keypointMarker;
};

struct ElementSize{
    uint8_t sizePointMarker;
    uint8_t sizeKeypointMarker;
};
struct Kp_and_Lm_cv {
    Point2d kp;
    Point3d lm_w;
};


enum PointType{
    keypoint = 0,
    predicted = 1
};

class Visualizer {
public:
    Visualizer();
    Visualizer(string name, Mat image);
    void Ellipse (Mat image, double angle);
    void FilledCircle(Mat image, Point center);
    void Polygon(Mat img);
    void Line(Mat img, Point start, Point end);
    void setKeypoints(list<Point2d> &kp_list);
    void ShowPoints(list<Point> kp_list,PointType pt_type);
    void SetElementColor(array<Scalar,3> c);
private:

public:
    Mat image;
    map<uint32_t,Kp_and_Lm_cv> keypoints_and_landmarks;
    list<Point> kp_list;
    list<Point> predictPoints_list;
    ElementColors visualizer_colors;
    ElementMarkers visualizer_markers;
    ElementSize visualizer_size;
    string windowName;
    uint32_t rows,cols;
};


#endif //C__PROGRAMS_VISUALIZER_H
