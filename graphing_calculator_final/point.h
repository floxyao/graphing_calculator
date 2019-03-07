#ifndef POINT_H
#define POINT_H
#include "const.h"
#include <iostream>
using namespace std;

/*-------------------------------------------------------
 * Point Structure
 * Private Member Variables: x and y
 --------------------------------------------------------*/
struct Point
{
private:
    double x;
    double y;

public:
    //Default Constructors
    Point():x(0.0), y(0.0){}
    Point(double xVal, double yVal):x(xVal),y(yVal){}
    double getX();
    double getY();

    friend ostream &operator <<(ostream &out, const Point &print){
        out << "(" << print.x << " , " << print.y << ")";}

};

/*============Point Member Functions==========*/
/*-------------------------------------------------------
 * getX(); getY();
 * Returns the x and y coordinate
 * X_REPOS and Y_REPOS are constnats added because the
 * coordinate plane in QT is not the same as a regular
 * Y/X axis...so I repositioned the graph by adding these
 * values so it would show up in the middle
 --------------------------------------------------------*/
double Point::getX(){
    return x; //+X_REPOS; //reposition
}
double Point::getY(){
    return y; //-Y_REPOS;
}

#endif // POINT_H
