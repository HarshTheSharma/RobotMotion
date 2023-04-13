#include <iostream>
#include <cmath>
#include <string>
#include "RhinoMath.h"
#include <windows.h>        //Used for Sleep method
#include "RhinoSpecific.h"
using namespace std;


//Note: This routine develops a command string using a string
//and again as a character array for demo. You may pick one.
bool RhinoSpecific::MotoMoveServo(char c, int Distance)
{
	double tempdistance1 = 0.0;
	double tempdistance2 = 0.0;
	double NewDistanceDifference = Distance;
	double DmotorDistance = 0.0;

	if (c == 'E')
	{
		tempdistance1 = Distance;
		NewDistanceDifference = TickAng1 - tempdistance1; //E motor
		TickAng1 = tempdistance1;
		Distance = (int)NewDistanceDifference;
		EmotorDistance = NewDistanceDifference;
	}
	EmotorDistance2 = EmotorDistance;

	if (c == 'D')
	{
		tempdistance2 = Distance;
		NewDistanceDifference = TickAng2 - tempdistance2;
		TickAng2 = tempdistance2;
		DmotorDistance = NewDistanceDifference - EmotorDistance2;
		Distance = (int)DmotorDistance;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////

		//Add take distance and current tick count TickAng1 and TickAng2
		//and move only the difference betweeb TickAngs and current TickAngs
		//          1. Calc diffrence between where I am and where goint
		//             move only that difference TickAng1 and TickAng2
		//          2. Store the complete value 
	int count = Distance / 50;      //Get loop count
	int cntRem = abs(Distance % 50); //Get remainder
	char Number[3] = { 0 };                  //Two characters plus the NULL terminator
	char direction;
	char* RobCmd = new char[80];     //C string cmd for Rhino
	string RoboCommand = "";         //Blank build string
	bool complete = false;

	//Assign the servo motor letter and direction
	RoboCommand += c;         // Assign motor
	direction = (Distance > 0) ? '+' : '-';
	RoboCommand += direction; // Assign directiom
	RoboCommand += "50";      //Default for loop

	//turns roboCommand into a string?? /b
	strcpy_s(RobCmd, RoboCommand.length() + 1, RoboCommand.c_str());
	for (int cnt = 0; cnt < abs(count); cnt++)
	{ //Move by fixed number loop.
		Sleep(50);  //Replace Sleep commands with wait command if time permits
		robo << RobCmd;
		//Sleep(120);
	}

	//Create string to handle remainder
	RoboCommand = "";        //Clear string
	RoboCommand += c;        //Assign motor
	RoboCommand += direction;//Assign direction
	_itoa_s(cntRem, Number, 3, 10);
	RoboCommand += Number;   //Assign remainder as characters
	strcpy_s(RobCmd, RoboCommand.length() + 1, RoboCommand.c_str());
	Sleep(50);
	robo << RobCmd;
	//Sleep(120);
	delete[] RobCmd;   //5_17 add
	return complete;
}