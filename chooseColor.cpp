#include <iostream>
#include <string>
#include "chooseColor.h"
#include "constants.h"

using namespace std;

//chooseColor.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//This function is used to set color of rectangle and pattern.

int chooseColor(string colorMethodChosen){
  int colorChosen = 0;//for cin
  bool colorIndicator;//for checking cin is valid
  
  cout << RED_OPTION << ". Red" << endl;
  cout << GREEN_OPTION << ". Green" << endl;
  cout << BLUE_OPTION << ". Blue" << endl;
  cout << BLACK_OPTION << ". Black" << endl;
  cout << WHITE_OPTION << ". White" << endl;

  if(colorMethodChosen == COLOR_REC){
    cout << "Enter int for rectangle color:";
  }
  else if(colorMethodChosen == COLOR_PATTERN){
    cout << "Enter int for pattern color:";
  }
  else{
    cout << "Enter int for transparency color:";
  }
  
  colorIndicator = INVALID_COLOR_INDICATOR;
  while(!colorIndicator){
    cin >> colorChosen;
    
    if(cin.fail()){
      cout << "Color Invalid, please enter a number between"
           << RED_OPTION << " - " << WHITE_OPTION << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      colorIndicator = INVALID_REC_ROW_COL_INDICATOR;
    }
    else if(colorChosen > WHITE_OPTION || colorChosen < RED_OPTION){
      cout << "Color Invalid, please enter a number between"
           << RED_OPTION << " - " << WHITE_OPTION << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      colorIndicator = INVALID_COLOR_INDICATOR;
    }
    else{
      colorIndicator = VALID_COLOR_INDICATOR;
    }
  }
  return colorChosen;
};
