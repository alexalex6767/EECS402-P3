#include <fstream>
#include <string>
#include <iostream>
#include "RowColumnClass.h"
#include "PatternClass.h"
#include "ColorClass.h"
#include "constants.h"

using namespace std;

//PatternClass.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//This class is to create a patternClass from different method

PatternClass::PatternClass(){
  patternUpperLeft = RowColumnClass();
  patternColor = ColorClass();
  patternWidth = PAT_INIT_WIDTH;
  patternHeight = PAT_INIT_WIDTH;
  patternPtr = 0;
}

bool PatternClass::readPatternFile(string inputPatternFile){
  int actualPixels;
  int expectedPixels;
  actualPixels = INIT_INPUT_PIXEL;
  
  //end of file indicator
  string eofIndicator;
  
  ifstream inFile;
  inFile.open(inputPatternFile.c_str());
  
  if(inFile.fail()){
    cout << "Unable to open input file: " << inputPatternFile << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  }
  
  //Read second line from the file
  int inPatternWidth;
  int inPatternHeight;
  inFile >> inPatternWidth >> inPatternHeight;
  
  //Check if width and height are valid (you might want to add more checks)
  if(inPatternWidth <= MIN_PAT_WIDTH){
    cout << "Invalid width in txt file: "
         << inputPatternFile << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  }
  else if(inPatternHeight <= MIN_PAT_HEIGHT){
    cout << "Invalid height in txt file: "
         << inputPatternFile << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  };
  
  patternWidth = inPatternWidth;
  patternHeight = inPatternHeight;
  
  expectedPixels = patternWidth * patternHeight;
  
  //create pattern at heap
  patternPtr = new int*[patternHeight];
  for(int i = 0; i < patternHeight; i++){
    patternPtr[i] = new int[patternWidth];
  }
  
  //Read pixels inside to the pattern
  int inputPatternPixel;
  for(int i = 0; i < patternHeight; i++){
    for(int j = 0; j < patternWidth; j++){
      inFile >> inputPatternPixel;
      if(inFile.eof()) {
        // Handle the case where EOF is reached before expectedPixels
        cout << "End of file reached at Row " << i
             << " Col " << j
             << " before reading all expected pixels."
             << endl;
        inFile.clear();
        inFile.ignore(LARGE_NUMBER, NEW_LINE);
        inFile.close();
        return INVALID_INPUT_INDICATOR;
      }
      if(inFile.fail()) {
        // Handle the case whether there is invalid input
        cout << "Failed reading at Row " << i
             << " Col " << j
             << " before reading all expected pixels."
             << endl;
        inFile.clear();
        inFile.ignore(LARGE_NUMBER, NEW_LINE);
        inFile.close();
        return INVALID_INPUT_INDICATOR;
      }
      if((inputPatternPixel != 0) && (inputPatternPixel != 1)) {
        // Handle the case whether there is invalid input
        cout << "Sth not 0 or 1 found at Row " << i
             << " Col " << j
             << " before reading all expected pixels."
             << endl;
        inFile.clear();
        inFile.ignore(LARGE_NUMBER, NEW_LINE);
        inFile.close();
        return INVALID_INPUT_INDICATOR;
      }
      else{
        actualPixels++;
        patternPtr[i][j] = inputPatternPixel;
      };
    }
  }//end of read pixel
  
  //To see whether the pixels count is correct;
  if(actualPixels != expectedPixels){
    cout << "Number of pixels read does not match the expected number."
         << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  }
  
  //eof
  //will need a variable to save the inFile.eof()
  inFile >> eofIndicator;
  if(eofIndicator != ""){
    cout << "End Of File does not meet,"
         << " RGB value is more than the image size."
         << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return VALID_INPUT_INDICATOR;
  }
  else{
    // Close the file
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
      
    return VALID_INPUT_INDICATOR;
  };//end of check last input
};

//we need to set the upperleft corner of the pattern
void PatternClass::setPatternLocation(int inPatternRow, int inPatternCol){
  patternUpperLeft.setRowCol(inPatternRow, inPatternCol);
};

//This is for set color
void PatternClass::setPatternColor(int colorChosen){
  if(colorChosen == RED_OPTION){
    patternColor.setToRed();
  }
  else if(colorChosen == GREEN_OPTION){
    patternColor.setToGreen();
  }
  else if(colorChosen == BLUE_OPTION){
    patternColor.setToBlue();
  }
  else if(colorChosen == BLACK_OPTION){
    patternColor.setToBlack();
  }
  else if(colorChosen == WHITE_OPTION){
    patternColor.setToWhite();
  }
};

//we need to set the color of the pattern
void PatternClass::setPatternWidth(int inPatternWidth){
  patternWidth = inPatternWidth;
};

//we need to set the color of the pattern
void PatternClass::setPatternHeight(int inPatternHeight){
  patternHeight = inPatternHeight;
};

//getter
//get Pattern upperLeft location
RowColumnClass PatternClass::getPatternUpperLeft(){
  return patternUpperLeft;
};

//get Pattern Color
ColorClass PatternClass::getPatternColor(){
  return patternColor;
};

//get Pattern Width
int PatternClass::getPatternWidth(){
  return patternWidth;
};

//get Pattern Height
int PatternClass::getPatternHeight(){
  return patternHeight;
};

//get PatternPointer
int **PatternClass::getPatternPointer(){
  return patternPtr;
}




