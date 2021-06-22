//
// Created by jagatpreet on 3/3/21.
//

#include "../include/Visualizer.h"
Visualizer::Visualizer(){

}

Visualizer::Visualizer(string name, Mat img){
    windowName = name;
    image = img;
}

void Visualizer::Ellipse( Mat img, double angle )
{
    int thickness = 2;
    int lineType = 8;
    ellipse( img,
             Point( rows/2, cols/2 ),
             Size( rows/4, cols/16 ),
             angle,
             0,
             360,
             Scalar( 255, 0, 0 ),
             thickness,
             lineType );
}
void Visualizer::FilledCircle( Mat img, Point center )
{
    circle( img,
            center,
            rows/32,
            Scalar( 255, 0, 255 ),
            FILLED,
            LINE_8 );
}
void Visualizer::Polygon( Mat img )
{
    int lineType = LINE_8;
    Point rook_points[1][20];
    rook_points[0][0]  = Point(    rows/4,   7*cols/8 );
    rook_points[0][1]  = Point(  3*rows/4,   7*cols/8 );
    rook_points[0][2]  = Point(  3*rows/4,  13*cols/16 );
    rook_points[0][3]  = Point( 11*rows/16, 13*cols/16 );
    rook_points[0][4]  = Point( 19*rows/32,  3*cols/8 );
    rook_points[0][5]  = Point(  3*rows/4,   3*cols/8 );
    rook_points[0][6]  = Point(  3*rows/4,     cols/8 );
    rook_points[0][7]  = Point( 26*rows/40,    cols/8 );
    rook_points[0][8]  = Point( 26*rows/40,    cols/4 );
    rook_points[0][9]  = Point( 22*rows/40,    cols/4 );
    rook_points[0][10] = Point( 22*rows/40,    cols/8 );
    rook_points[0][11] = Point( 18*rows/40,    cols/8 );
    rook_points[0][12] = Point( 18*rows/40,    cols/4 );
    rook_points[0][13] = Point( 14*rows/40,    cols/4 );
    rook_points[0][14] = Point( 14*rows/40,    cols/8 );
    rook_points[0][15] = Point(    rows/4,     cols/8 );
    rook_points[0][16] = Point(    rows/4,   3*cols/8 );
    rook_points[0][17] = Point( 13*rows/32,  3*cols/8 );
    rook_points[0][18] = Point(  5*rows/16, 13*cols/16 );
    rook_points[0][19] = Point(    rows/4,  13*cols/16 );
    const Point* ppt[1] = { rook_points[0] };
    int npt[] = { 20 };
    fillPoly( img,
              ppt,
              npt,
              1,
              Scalar( 255, 255, 255 ),
              lineType );
}

void Visualizer::Line( Mat img, Point start, Point end )
{
    int thickness = 2;
    int lineType = LINE_8;
    line( img,
          start,
          end,
          Scalar( 255, 0, 0 ),
          thickness,
          lineType );
}

void Visualizer::ShowPoints(list<Point> kp_list,PointType pt_type){
    MarkerTypes marker;
    Scalar color;
    int markerSize;
    switch (pt_type){
        case keypoint:
            marker = visualizer_markers.keypointMarker;
            color = visualizer_colors.markerColor;
            markerSize = 15;
            break;
        case predicted:
            marker = visualizer_markers.pointMarker;
            color = visualizer_colors.pointColor;
            markerSize = 5;
            break;
    }

    for(auto it = kp_list.begin(); it != kp_list.end();it++ ){
        drawMarker(image,*it,color,marker,markerSize,1,LINE_8);
    }
}

void Visualizer::SetElementColor(array<Scalar,3> c){
    visualizer_colors.markerColor = c[0];
    visualizer_colors.lineColor = c[1];
    visualizer_colors.pointColor = c[2];
}
