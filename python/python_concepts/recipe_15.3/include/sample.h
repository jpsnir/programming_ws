#include <math.h>
extern int gcd(int x, int y);
extern int in_mandel(double x0, double y0, int n);
extern double avg(double *a, int n);
extern int divide(int a, int b, int *remainder);

/* A C data structure */
typedef struct Point {
  double x,y;
} Point;

extern double distance(Point *p1, Point *p2);
