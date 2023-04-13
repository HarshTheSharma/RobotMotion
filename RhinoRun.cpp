#define _USE_MATH_DEFINES
#include "MasterHeader.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Line.h"
#include "RobotMotion.h"

using namespace std;


int main()
{  
	PointXY targetPt{12,12};
	PointXY home{ 9,9 };
	RobotMotion Run;
	Run.Moveto('1', targetPt, targetPt);
	targetPt = { 14,9 };
	Run.Moveto('1', targetPt, targetPt);
	Run.Moveto('1', home, home);
}
