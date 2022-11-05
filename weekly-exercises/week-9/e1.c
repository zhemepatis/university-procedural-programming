#include <stdio.h>
#include <math.h>

typedef struct Point {double x, y;} Point;

Point createPoint(double x, double y);
void printPoint(Point p);
double getDistance(Point a, Point b);

int main() {
    double distance = getDistance(createPoint(0.0, 0.0), createPoint(-4.0, 5.0));
    return 0;
}

Point createPoint(double x, double y) {
    Point point;

    point.x = x;
    point.y = y;

    return point;
}

void printPoint(Point p) {
    printf("(%f, %f)\n", p.x, p.y);
}

double getDistance(Point a, Point b) {
    return sqrt(pow((b.x-a.x), 2) + pow((b.y-a.y), 2));
}



