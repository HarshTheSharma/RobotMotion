
#include "RhinoMath.h"
#include <cmath>
using namespace std;


RhinoMath::RhinoMath(double ArmA, double ArmB)
{
	(*this).ArmA = ArmA;
	this->ArmB = ArmB;
}

double RhinoMath::CompAng2(double x, double y) //Replace with point pair
{
	//comments

	double tempN = pow(x, 2.0) + pow(y, 2.0)
		- pow(ArmA, 2.0) - pow(ArmB, 2.0);
	double tempD = 2.0 * ArmA * ArmB;
	return acos(tempN / tempD);
}

double RhinoMath::CompAng1(double x, double y, double Ang2)//Replace with point pair
{
	double tempN = ArmA * sin(Ang2);
	double tempD = pow((pow(x, 2.0) + pow(y, 2.0)), .5);
	return (asin(tempN / tempD) + atan(y / x));
}

double Degree(double rad)
{
	return (rad*(180 / 3.14));
}

AnglePair RhinoMath::getAngpair(PointXY xy) //Replace with point pair
{
	double angle1, angle2;
	AnglePair Pair;
	angle2 = CompAng2(xy.X, xy.Y);
	angle1 = CompAng1(xy.X, xy.Y, angle2);

	angle1 = Degree(angle1);
	angle2 = Degree(angle2);

	Pair.Ang1 = angle1;
	Pair.Ang2 = angle2;

	return Pair;
}

