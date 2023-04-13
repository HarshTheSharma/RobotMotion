#include <iostream>
#include <iomanip>
#include "MasterHeader.h"
#include "RobotMotion.h"
using namespace std;

void RobotMotion::Moveto(char Cmd, PointXY TargPos, PointXY CentPos)
{
    //WE will compartmentalize this later after it works
    PointXY WorkingXY = TargPos;
    PointXY XYPair{ 0,0 };
    WorkingXY.X -= CurrPos.X;  //Construct line points from the origin
    WorkingXY.Y -= CurrPos.Y;
    PointXY Pt2;
    PointXY Pt1;

    //Line specific - Will simplify once working
    double angle;           //Holds the angle of travel.
    double distance;        //Holds length of trabel.
    double unitstep = 0.5;  //Set line segment distance.
    double steps;           //Holds num. steps for loop.
    PointXY Ptret;          //Working return variable for points.


    int testint;
    switch (Cmd)
    {
    case '0':
    case '1': //code to call line
        Pt2.X = (TargPos.X - CurrPos.X); Pt2.Y = (TargPos.Y - CurrPos.Y); //Target destination point.
        Pt1.X = 0; Pt1.Y = 0;                                                                         //We will assume lines start at origin.
        angle = LineTest.getAngleFromXY(Pt1, Pt2);                                  //Get direction angle.
        distance = LineTest.getLength(Pt1, Pt2);                                         //Get length of travel.
        steps = LineTest.getLineSteps(unitstep);                                         //Get number of steps.
        // cout << "  Distance: " << distance << endl;
         //cout << "     Angle: " << angle << endl;
         //cout << "Unit Steps: " << steps << endl << endl;

        distance = 0; //Assume line starts at (0,0) you will need to add the
        //offset to project to robot position.
        for (int i = 0; i < steps; i++)
        {
            distance += unitstep;                                                      //Update distance by unit step distance
            Ptret = LineTest.getNextPt(angle, Pt1, Pt2, distance); //Get next point
            //account for offset to current robot position
            //cout << fixed << setprecision(2) << " " << Ptret.X + CurrPos.X << "  "; //X
            //cout << fixed << setprecision(2) << " " << Ptret.Y + CurrPos.Y << endl; //Y
            XYPair.X = Ptret.X + CurrPos.X;

            XYPair.Y = Ptret.Y + CurrPos.Y;
            Rhino.MoveToXY(XYPair);
        }
        //Move to final destination which is < unit step distance.
        XYPair.X = Pt2.X + CurrPos.X;
        XYPair.Y = Pt2.Y + CurrPos.Y;
        Rhino.MoveToXY(XYPair);
        CurrPos = TargPos;
        cout << "Reached X: " << fixed << setprecision(2) << TargPos.X << endl; //X
        cout << "Reached Y: " << fixed << setprecision(2) << TargPos.Y << "\n_______________________________________________________\n" << endl;//Y
        testint = 2;  //Test point to make a break point (remove before flight)
        break;
    case '2'://future arc
        //Make sure we have center position updated
        //Modify to take into account Center point offset
        //Create arc about the origin (0,0)
        //As we did for the line
        cout << "called G2" << endl;
        //See that the CenterPos is added as a parameter so we can
        //composate for (0,0) origin calculations
      //  TestCirc.PlotArc(Pt1,  Pt2, "CW", unitstep, CentPos);
        break;
    case '3'://You may want to scrap case 3 and redo based on the case 2 G02 code.
        //Watch the step count and angle distance calculations for moving
        //in the oposite direction.  If we know the steps around the circle.
        //We might simplify by taking the total steps around the circle and 
        //subtracting the G02 arc...  or you can examine how I did it.
        //TestCirc.PlotArc(Pt1,  Pt2, "CCW", unitstep, CentPos);
        break;
    default: cout << "Where am I " << endl;
    } //Have moved to target
    //Store target into current position after we arrive
    CurrPos.X = TargPos.X;
    CurrPos.Y = TargPos.Y;
}

bool RobotMotion::MotoMoveServoFout()
{
    RoboMotion.MotoMoveServo('F', -20);
    return true;
}

bool RobotMotion::MotoMoveServoFin()
{
    RoboMotion.MotoMoveServo('F', 20);
    return true;