#ifndef MOVETOPOINT_H
#define MOVETOPOINT_H

#include "RhinoSpecific.h"
#include "RhinoMath.h"

class MoveToPoint{
  private:
     RhinoSpecific RoboMotion;
     RhinoMath      RoboCalc;

  public:
     bool MoveToXY(PointXY);
};

#endif