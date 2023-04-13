#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "MasterHeader.h"
#include "MoveToPoint.h"
class circle
{   //Note: C trig functions return radians.  I have converted to degrees for demonstration
	private:
      MoveToPoint* RoboMovetoPoint = nullptr;////////// Reference to avoid multiple tserial.
      double Angle1 = 0.0, Angle2 = 0.0, AngleDist = 0.0, Radius = 0.0;
      double Steps = 0.0,   Step = 0.0,  UnitDist = 0.0;
	  double getAngleDist(){return AngleDist;}        //Return Ang Dist. between points
	  double PointAngle   (const  PointXY &P1);       //Return Angle based on XY point
      double getCirc(double Radius);                  //Return Circumf.
      double getAngleSteps(double UnitStep,  double Radius); //Get Num Steps around arc.
      PointXY PlotPoint = {0.0,0.0};
      char textch = ' ';
      double test = 0.0;
      int counter = 0;
   public:
      XYPoint WorkingPtMv = { 0,0 };  //Combine with PointXY 
	  double getAngle1(){return Angle1;}              //Return Angle1
      double getAngle2(){return Angle2;}              //Return Angle2
      double getStep(){return Step;}                  //Return UnitStep
      double AngleBWPoints(double Ang1, double Ang2); //Return Angular Distance
      void  initArc(const  PointXY &P1, const  PointXY &P2, const double UnitDistance); //Initialize Circle params
      PointXY  getXYAngleHyp(double Angle);             //Return XYPoint given an angle.
      void  DoitC( PointXY &Pt1,   PointXY &Pt2, std::string dir, const double unitStep, PointXY &Cpt);
       //Method to set MoveToPoint.  Could be set in constructor
      void  setMovetoPoint(MoveToPoint* RoboMove) { RoboMovetoPoint = RoboMove; }//Set MoveToPoint
};
#endif