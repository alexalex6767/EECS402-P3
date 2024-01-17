#ifndef Rectangle_h
#define Rectangle_h

#include "RowColumnClass.h"
#include "ColorClass.h"

//RectangleClass.h, project3
//Programmer: Tzu-Yu Peng, typeng
//This class is to create a rectangle.

class RectangleClass{
  private:
    RowColumnClass upperLeft;
    RowColumnClass lowerRight;
    ColorClass rectangleColor;
  
  public:
    //Default Constructor
    RectangleClass();
    
    //member function
    //This is for set color
    void setRecColor(int colorChosen);

    //This is for set upperleft
    void setUpperLeft(int inRow, int inCol);

    //This is for set upperleft
    void setLowerRight(int inRow, int inCol);

    //Getters
    //This is for users to get the upperLeft position
    RowColumnClass getUpperLeft();
  
    //This is for users to get the lowerRight position
    RowColumnClass getLowerRight();
  
    //This is for users to get the Rectangle Class Color
    ColorClass getRecColorClass();
  
    //This is for users to get the width of the rectangle
    int getWidth();
  
    //This is for users to get the height of the rectangle
    int getHeight();

};

#endif /* RectangleClass_h */
