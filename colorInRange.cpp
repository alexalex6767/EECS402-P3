#include <iostream>
#include "constants.h"
#include "colorInRange.h"

using namespace std;

//colorInRange.h, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains a function for checking whether color is in the range.

bool colorInRange(int colorInput){
  if((colorInput <= MAX_COLOR_VALUE) && (colorInput >= MIN_COLOR_VALUE)){
    return true;
  }
  else{
    return false;
  };
};
