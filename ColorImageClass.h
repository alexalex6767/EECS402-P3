#ifndef ColorImageClass_h
#define ColorImageClass_h

#include "ColorClass.h"
#include "showMainMenu.h"
#include <iostream>
#include <string>

using namespace std;

//ColorImageClass.h, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains ColorImageClass's definition and method prototype
//This class is for manipulating the things that
//will need to be add to an image

//This class is used to set columns and rows
class ColorImageClass{
  private:
    //value read in the input file
    int ppmWidth;
    int ppmHeight;
    int maxColorValueInput;
    string magicNumberInput;
    ColorClass **colorClassArrayObjectPtr;
    ColorClass transColor;
  
  public:
    //Default constructor
    ColorImageClass();
  
    //Project3 Range
    bool initializeFromPpmFile(string ppmFileName);
  
    //Make Rectangle on the Base Image
    void makeRectangleOnBaseImg();
  
    //Make Pattern On the Base Image
    void makePatternOnBaseImg();
  
    //Insert Image on the Base Image
    bool insertImageOnBaseImg();
  
    //Write out the image
    void writeOutImg(string outputName);
  
    //get color image class width
    int getWidth();
    
    //get color image class height
    int getHeight();
  
    //get max color
    int getMaxColorInput();
  
    //get magic number for write out
    string getMagicNumber();
  
    //set Trans color
    void setTransColor(int setColor);
  
    //get Trans Color
    int getTransRed();
  
    int getTransGreen();
  
    int getTransBlue();
};


#endif /* ColorImageClass_h */
