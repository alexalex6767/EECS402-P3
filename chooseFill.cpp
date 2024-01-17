#include "chooseFill.h"
#include "constants.h"
#include <iostream>

using namespace std;

//chooseFill, Project3
//Programmer Tzu-Yu Peng, typeng
//This function is for choosing rectangle fill or not

int chooseFill(){
  int fillOption = INIT_VALUE;
  bool fillIndicator = INVALID_FILL;
  
  cout << NOT_FILL << ". No" << endl;
  cout << FILL << ". Yes" << endl;
  cout << "Enter int for rectangle fill option: ";
  while(!fillIndicator){
    cin >> fillOption;
    
    if(cin.fail()){
      cout << "Fill Invalid, please enter a number between"
           << FILL << " - " << NOT_FILL << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      fillIndicator = INVALID_FILL;
    }
    
    else if(fillOption > FILL || fillOption < NOT_FILL){
      cout << "Fill Invalid, please enter a number between"
           << FILL << " - " << NOT_FILL << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      fillIndicator = INVALID_FILL;
    }
    
    else{
      fillIndicator = VALID_FILL;
    }
  }
  return fillOption;
};
