#include <iostream>
#include <string>
#include "ColorImageClass.h"
#include "showMainMenu.h"
#include "constants.h"

using namespace std;

//main.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This project is for users to add, insert, highlight images they want.

int main()
{
  //read file and store as an ColorImageClass
  string baseFile;
  ColorImageClass baseImg;
  cout << "Enter string for PPM image file name to load: ";
  cin >> baseFile;
  if(baseImg.initializeFromPpmFile(baseFile)){
    int chosenAction = INIT_VALUE;
    
    //choose which option
    while(chosenAction != EXIT_PROGRAM){
      
      //go to main menu
      //Choose which Action to Execute
      chosenAction = showMainMenu();
      
      //when user chooses the first action
      if(chosenAction == ANNOTATE_RECTANGLE){
        baseImg.makeRectangleOnBaseImg();
      };
      
      //when user chooses the second action
      if(chosenAction == ANNOTATE_PATTERN){
        baseImg.makePatternOnBaseImg();
      };
      
      //when user chooses the third action
      if(chosenAction == INSERT_IMAGE){
        int insertImageIndicator = INVALID_IMAGE_INPUT;
        while(!insertImageIndicator){
          if(!baseImg.insertImageOnBaseImg()){
            insertImageIndicator = INVALID_IMAGE_INPUT;
          }
          else{
            insertImageIndicator = VALID_IMAGE_INPUT;
          };
        };
      };
      
      //when user chooses the fourth action
      if(chosenAction == WRITE_OUT){
        string outputName;
        cout << "Enter string for PPM file name to output: " ;
        cin >> outputName;
        baseImg.writeOutImg(outputName);
      };
        
      //when user chooses the fifth action
      if(chosenAction == EXIT_PROGRAM){
        cout << "Thank you for using this program" << endl;
      };
      
    };//end of while
      
  };//end of if
  
  cin.clear();
  cin.ignore(LARGE_NUMBER, NEW_LINE);
  return 0;
};
