#include <iostream>
#include "RowColumnClass.h"
#include "constants.h"

using namespace std;

//RowColumnClass.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains RowColumnClass's implementation
//This class is for choosing row and column


//RowColumnClass
//Constructor
//Default is to set row and column to -99999
RowColumnClass::RowColumnClass(){
  rowIndex = DEFAULT_ROW_COL;
  colIndex = DEFAULT_ROW_COL;
};
RowColumnClass::RowColumnClass(int inRow, int inCol){
  rowIndex = inRow;
  colIndex = inCol;
};

//This member function is to set Row and Col at the same time
void RowColumnClass::setRowCol(int inRow, int inCol){
  rowIndex = inRow;
  colIndex = inCol;
};

//This member function is to set Row
void RowColumnClass::setRow(int inRow){
  rowIndex = inRow;
};

//This member function is to set Col
void RowColumnClass::setCol(int inCol){
  colIndex = inCol;
};

//These two member function are to get the Row and Col value
int RowColumnClass::getRow(){
  return rowIndex;
};

int RowColumnClass::getCol(){
  return colIndex;
};

//This function is to add row and col value to the object
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol){
  rowIndex += inRowCol.rowIndex;
  colIndex += inRowCol.colIndex;
};

