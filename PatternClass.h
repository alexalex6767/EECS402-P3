#ifndef PatternClass_h
#define PatternClass_h

#include <iostream>
#include <string>
#include "ColorClass.h"
#include "RowColumnClass.h"

using namespace std;

//PatternClass.h, project3
//Programmer: Tzu-Yu Peng, typeng
//This class is to create a pattern.

//Constructor
class PatternClass{
  private:
    //need to store the Pattern's size, use the first two int of input file.
    int patternWidth; //first number in the file
    int patternHeight; //second number in the file
    RowColumnClass patternUpperLeft;
    ColorClass patternColor;
    int **patternPtr; //bc 2D array, will use pointer's pointer
    
  public:
    // Constructors
    PatternClass();//use each attribute's default constructors to create
  
    //member function
    // input file function
    bool readPatternFile(string inputPatternFile);
    
    //we need to set the upperleft corner of the pattern
    void setPatternLocation(int inPatternRow, int inPatternCol);
  
    //we need to set the color of the pattern
    void setPatternColor(int colorChosen);
  
    //we need to set the color of the pattern
    void setPatternWidth(int inPatternWidth);
  
    //we need to set the color of the pattern
    void setPatternHeight(int inPatternHeight);
  
    //getter
    //get Pattern upperLeft location
    RowColumnClass getPatternUpperLeft();
    
    //get Pattern Color
    ColorClass getPatternColor();
  
    //get Pattern Width
    int getPatternWidth();
  
    //get Pattern Height
    int getPatternHeight(); 
    
    //get Pattern Pointer
    int **getPatternPointer();


};

#endif /* PatternClass_h */
