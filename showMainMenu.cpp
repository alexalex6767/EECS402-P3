#include <iostream>
#include "showMainMenu.h"
#include "constants.h"

using namespace std;

//showMainMenu.h, project3
//Programmer: Tzu-Yu Peng, typeng
//This function is used to show main menu.

int showMainMenu(){
  int whichAction = INIT_VALUE;
  bool validInputFound = INVALID_INPUT_INDICATOR;
  
  cout << ANNOTATE_RECTANGLE << ". Annotate image with rectangle" << endl;
  cout << ANNOTATE_PATTERN << ". Annotate image with pattern from file" << endl;
  cout << INSERT_IMAGE << ". Insert another image" << endl;
  cout << WRITE_OUT << ". Write out current image" << endl;
  cout << EXIT_PROGRAM << ". Exit the program" << endl;
  cout << "Enter int for main menu choice: ";
  
  while(!validInputFound){
    cin >> whichAction;
    if(cin.fail()){
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      cout << endl << "Fail state!" << endl;
      cout << "Try again - Enter an integer: ";
      validInputFound = INVALID_INPUT_INDICATOR;
    }
    else if(whichAction > EXIT_PROGRAM || whichAction < ANNOTATE_RECTANGLE){
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      cout << endl << "Fail state!" << endl;
      cout << "Try again - Enter a integer that is between "
           << ANNOTATE_RECTANGLE << " - " << EXIT_PROGRAM << endl;
      validInputFound = INVALID_INPUT_INDICATOR;
    }
    else{
      validInputFound = VALID_INPUT_INDICATOR;
    };
  }
  return whichAction;
}
