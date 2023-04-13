#ifndef PARSE_H
#define PARSE_H
#include "MasterHeader.h"
#include "RobotMotion.h"
#include<fstream>
#include<string>


class Parse
{
private:
    std::ifstream GCODEin;                 //GCode input file
    char     GCODE = ' ';             //Store Current G command
    double   CurrentX, CurrentY;      //Store current position
    double   X = 0.0, Y = 0.0, I = 0.0, J = 0.0; //Store new target position
    unsigned index;                   //Index to individual command ln.
    std::string CommandLine;               //Store individual command lines.
    RobotMotion RoboTestDemo;
    PointXY Centertpt, targetpt;       //Added to allow passing to existing moveto cmd
    PointXY WorkingPtMv = { 0,0 };
    PointXY Current = { 0,0 };
    PointXY WorkingPt = { 0,0 };
    PointXY WorkingCur = { 0,0 };
    bool isWriting = true;

        

public:
    Parse(std::string nameFile) { GCODEin.open(nameFile); }
    ~Parse() { GCODEin.close(); }
    void parseLine();
    void getGODE();
    void getX();
    void getY();
    void getI();
    void getJ();

};

#endif // !PARSE_H