#ifndef RobotMotion_H
#define RobotMotion_H

#include "MasterHeader.h"  //Common point and angle types
#include "Line.h"          //Developed week 3
//#include "Circle.h"      //Will start development Next week
#include "MoveToPoint.h"   //Used in last weeks main demo
class RobotMotion

{
private:
    //We need to set an XY reference point as we did with the 750,750
    PointXY CurrPos = { 9.0,9.0 }; //Home or overall start position
    PointXY CentPos = { 0.0,0.0 }; //Default center point for Arcs and Circles TBD
    Line LineTest;               //Instance of line object
    //      Circle TestCirc;             //We will develop the circle class next week
    MoveToPoint   Rhino;         //Was in our main last week
public:   //       0123            Target           Center for arcs+
    void Moveto(char Cmd, PointXY TargPos, PointXY CentPos);
    bool MotoMoveServoFout();
    bool MotoMoveServoFin();
};
#endif