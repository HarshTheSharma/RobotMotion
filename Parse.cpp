#include "Parse.h"
#include <iostream>
#include <iomanip>
void Parse::parseLine()
{
    unsigned LineLength;  //Hold lengtgh of current line.
    if (!GCODEin.eof() && GCODE != '8')    //Read if not end of file
        getline(GCODEin, CommandLine);
    else
        return;
    LineLength = CommandLine.length();

    //Collect G XYIJ values in each line
    for (index = 0; index < LineLength; index++)
    {
        //cout << CommandLine[index];
        switch (CommandLine[index])
        {
        case 'G': getGODE();
            break;
        case 'X': getX();
            break;
        case 'Y': getY();
            break;
        case 'I': getI();
            break;
        case 'J': getJ();
            break;
        }
    }
    //std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
    //    << " I" << std::setw(7) << I << " J" << std::setw(7) << J;
    //PointXY Currentpt, targetpt;
    targetpt.X = X;
    targetpt.Y = Y;
    Centertpt.X = I;
    Centertpt.Y = J;
    switch (GCODE)
    {
    case '0': //call line class and populate the Gcommand in the class
        //IF Z != 1 move waist out 10 clicks set flag('QuilOutFlag'on board)
        //  move out 10 clicks and set QuilOutFlag to true
        //If Z == 0 check flag('QuilOutFlag'are we out) and move in 10
        //  move  in 10 clicks and set 'QuilOutFlag' to false
        //Add Mov XY for speed,.. or you can use line, 
        switch (isWriting) {
        case 1:
            isWriting = RoboTestDemo.penUp();
            break;
        case 0:
            isWriting = RoboTestDemo.penDown();
            break;
        }
        break;

    case '1': //call line class and populate the Gcommand in the class
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        RoboTestDemo.Moveto('1', targetpt, Centertpt); //G01
        //call to line method
        break;
    case '2': //call circle CW  and populate the Gcommand in the class
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        break;
    case '3': //call circle CCW and populate the Gcommand in the class
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        break;

    }
}

void Parse::getI()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]); //Append characters to a temp string
    I = atof(Temp.c_str());
    --index;
}

void Parse::getJ()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    J = atof(Temp.c_str());
    --index;
}

void Parse::getY()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    Y = atof(Temp.c_str());
    --index;
}

void Parse::getX()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    X = atof(Temp.c_str());
    --index;
}

void Parse::getGODE()
{
    GCODE = CommandLine[2]; //Grab the actual charcter for the G0,1,2,or 3
    index = 2;
}

//What happened to main

#include <iostream>
//include "MasterHeader.h"
//#include "RobotMotion2023.h"
#include "Parse.h"
using namespace std;
/*
int main()
{
    Parse DataIn("test1.txt");
    //DataIn.parseLine();
    while (1) //Do not use endless loops in final product fix next
    {
        DataIn.parseLine();
        //cin.get();
    }

    /*
    RobotMotion2023 RoboTestDemo;

    PointXY    XY1010 = { 9.0,10 };
    PointXY    XY0909 = { 9,9 };
    PointXY    XY0910 = { 10,9};


    PointXY    XYPair1 = {11,11}; //make sure you pick valid points
    PointXY    XYPair2 = {9,9};   //Note that I updated my points after
    PointXY    XYPair3 = {8,8};   //Note that I updated my points after
    PointXY    XYPair4 = {8,10};  //Note that I updated my points after
    PointXY    XYPair5 = {10,8};  //Note that I updated my points after

    PointXY    IJPair  = {12,10}; //Not actually used for G01 and G00
    //Arc2
    PointXY    XYArc2  = {19,13};
    PointXY    IJPair2 = {19,10};


    RoboTestDemo.Moveto('1', XY1010, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XY0909, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XY0910, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XY0909, IJPair); //G01
    system("pause");
    cout << "                                  ";


    RoboTestDemo.Moveto('1', XYPair1, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair2, IJPair); //G01 Home
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair3, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair2, IJPair); //G01 Home
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair4, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair2, IJPair); //G01 Home
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair5, IJPair); //G01
    system("pause");
    cout << "                                  ";
    RoboTestDemo.Moveto('1', XYPair2, IJPair); //G01 Home
    system("pause");
    cout << "                                  ";


    //We will investigate the circle class next week :-)
    //RoboTestDemo.Moveto('2', XYPairh, IJPair); //G02
    //system("pause");
    //RoboTestDemo.Moveto('2', XYArc2, IJPair2); //G02
    //system("pause");   *\
    return 0;
}
*/