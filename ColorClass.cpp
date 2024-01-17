#include <iostream>
#include <sstream>//still need to check
#include "ColorClass.h"
#include "constants.h"
#include "colorInRange.h"


using namespace std;

//ColorClass.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains ColorClass's implementation
//This class is for manipulating color


//ColorClass constructor
//Default is to full white, means RGB are all full
ColorClass::ColorClass(){
  redAmount = INIT_COLOR_VALUE;
  greenAmount = INIT_COLOR_VALUE;
  blueAmount = INIT_COLOR_VALUE;
};
ColorClass::ColorClass(int inRed, int inGreen, int inBlue){
  redAmount = inRed;
  greenAmount = inGreen;
  blueAmount = inBlue;
};

//set to specific colors
void ColorClass::setToBlack(){
  redAmount = MIN_COLOR_VALUE;
  greenAmount = MIN_COLOR_VALUE;
  blueAmount = MIN_COLOR_VALUE;
};
void ColorClass::setToRed(){
  redAmount = MAX_COLOR_VALUE;
  greenAmount = MIN_COLOR_VALUE;
  blueAmount = MIN_COLOR_VALUE;
};
void ColorClass::setToGreen(){
  redAmount = MIN_COLOR_VALUE;
  greenAmount = MAX_COLOR_VALUE;
  blueAmount = MIN_COLOR_VALUE;
};
void ColorClass::setToBlue(){
  redAmount = MIN_COLOR_VALUE;
  greenAmount = MIN_COLOR_VALUE;
  blueAmount = MAX_COLOR_VALUE;
};
void ColorClass::setToWhite(){
  redAmount = MAX_COLOR_VALUE;
  greenAmount = MAX_COLOR_VALUE;
  blueAmount = MAX_COLOR_VALUE;
};

void ColorClass::setTo(int inRed, int inGreen, int inBlue) {
  // If all input color values are in range, set color as input
  redAmount = inRed;
  greenAmount = inGreen;
  blueAmount = inBlue;
}

//overload function, use the other pixel's color
void ColorClass::setTo(ColorClass inColor){
  redAmount = inColor.redAmount;
  greenAmount = inColor.greenAmount;
  blueAmount = inColor.blueAmount;
};

// Member function to read color values from a PPM file
bool ColorClass::setColorFromPpm(ifstream &inFile) {
  int ppmRed;
  int ppmGreen;
  int ppmBlue;

  inFile >> ppmRed >> ppmGreen >> ppmBlue;

  //Check if the values are in the valid range
  if(!colorInRange(ppmRed) || !colorInRange(ppmGreen) || !colorInRange(ppmBlue)) {
    //Handle out-of-range values if needed
    return false;
  }
  else{
    //Set the color to the input values
    redAmount = ppmRed;
    greenAmount = ppmGreen;
    blueAmount = ppmBlue;
    return true;
  };
};

void ColorClass::setTransColor(int setColor){
  if(setColor == RED_OPTION){
    setToRed();
  }
  else if(setColor == GREEN_OPTION){
    setToGreen();
  }
  else if(setColor == BLUE_OPTION){
    setToBlue();
  }
  else if(setColor == BLACK_OPTION){
    setToBlack();
  }
  else if(setColor == WHITE_OPTION){
    setToWhite();
  }
}

//getter function
int ColorClass::getRedAmount(){
  return redAmount;
}

int ColorClass::getGreenAmount(){
  return greenAmount;
}

int ColorClass::getBlueAmount(){
  return blueAmount;
}

string ColorClass::writeColor(){
  ostringstream outColor;
  
  outColor.str("");
  outColor << redAmount << " " << greenAmount << " " << blueAmount << " ";
  return outColor.str();
}//still need to check
