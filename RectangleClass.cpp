#include "RectangleClass.h"
#include "ColorClass.h"
#include "constants.h"

//RectangleClass.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//This class is to create a rectangle from different method

//Constructors
//Default
RectangleClass::RectangleClass(){
  upperLeft = RowColumnClass();
  lowerRight = RowColumnClass();
  rectangleColor = ColorClass();
};

//member function
//This is for set color
void RectangleClass::setRecColor(int colorChosen){
  if(colorChosen == RED_OPTION){
    rectangleColor.setToRed();
  }
  else if(colorChosen == GREEN_OPTION){
    rectangleColor.setToGreen();
  }
  else if(colorChosen == BLUE_OPTION){
    rectangleColor.setToBlue();
  }
  else if(colorChosen == BLACK_OPTION){
    rectangleColor.setToBlack();
  }
  else if(colorChosen == WHITE_OPTION){
    rectangleColor.setToWhite();
  }
};

//This is for set upperleft
void RectangleClass::setUpperLeft(int inRow, int inCol){
  upperLeft.setRowCol(inRow, inCol);
};

//This is for set upperleft
void RectangleClass::setLowerRight(int inRow, int inCol){
  lowerRight.setRowCol(inRow, inCol);
}

//This is for users to get the upperLeft position
RowColumnClass RectangleClass::getUpperLeft(){
  return upperLeft;
};

//This is for users to get the lowerRight position
RowColumnClass RectangleClass::getLowerRight(){
  return lowerRight;
};

ColorClass RectangleClass::getRecColorClass(){
  return rectangleColor;
}

//This is for users to get the width of the rectangle
int RectangleClass::getWidth(){
  return (upperLeft.getCol() - lowerRight.getCol());
};

//This is for users to get the height of the rectangle
int RectangleClass::getHeight(){
  return (upperLeft.getRow() - lowerRight.getRow());
};

