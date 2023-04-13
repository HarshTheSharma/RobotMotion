#include "MasterHeader.h"
#include "MoveToPoint.h"
#include "RhinoMath.h"
#include <iostream>

bool MoveToPoint::MoveToXY(PointXY XYPointNew)
{
    bool Didit; //Holds True or False
    AnglePair CurrentAngs;

    CurrentAngs = RoboCalc.getAngpair(XYPointNew);  //Calculates the Angle 1 and 2 in degrees
    Didit = RoboMotion.MotoMoveServo('E', int(CurrentAngs.Ang1 / .12));
    Didit = RoboMotion.MotoMoveServo('D', int(CurrentAngs.Ang2 / .12));
    return true;
}
