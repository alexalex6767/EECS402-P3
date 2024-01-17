#ifndef RowColumnClass_h
#define RowColumnClass_h

//RowColumnClass.h, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains RowColumnClass's definition and method prototype
//This class is for seting Row and Column

class RowColumnClass{
  private:
    int rowIndex;
    int colIndex;
  
  public:
    //constructor
    RowColumnClass();//Default is to set row and column to -99999
    RowColumnClass(int inRow, int inCol);
  
    //This member function is to set Row and Col at the same time
    void setRowCol(int inRow, int inCol);
  
    //This member function is to set Row
    void setRow(int inRow);
  
    //This member function is to set Col
    void setCol(int inCol);
  
    //These two member function are to get the Row and Col value
    int getRow();
    int getCol();
  
    //This function is to add row and col value to the object
    void addRowColTo(RowColumnClass &inRowCol);
};

#endif /* RowColumnClass_h */
