#ifndef ColorClass_h
#define ColorClass_h
#include <iostream>
#include <fstream>

using namespace std;

//ColorClass.h, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains ColorClass's definition and method prototype
//This class is for manipulating color

class ColorClass{
  private:
    int redAmount;
    int greenAmount;
    int blueAmount;

  public:
    //constructor
    ColorClass();//Default is to full white, means RGB are all full
    ColorClass(int inRed, int inGreen, int inBlue);
  
    //set to specific colors
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
  
    //set colors by the value you want
    void setTo(int inRed, int inGreen, int inBlue);
  
    //set colors by the other object's color
    void setTo(ColorClass inColor);
  
    //setColorFrom Ppm
    bool setColorFromPpm(ifstream &inFile);
    
    //setTransColor
    void setTransColor(int setColor);
  
    //getter function
    int getRedAmount();
    int getGreenAmount();
    int getBlueAmount();
  
    //write ColorClass value to file
    string writeColor();
};

#endif
