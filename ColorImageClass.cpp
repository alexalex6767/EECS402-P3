#include <iostream>
#include <fstream>
#include <string>
#include "ColorImageClass.h"
#include "constants.h"
#include "ColorClass.h"
#include "RectangleClass.h"
#include "chooseFill.h"
#include "chooseColor.h"
#include "PatternClass.h"

using namespace std;

//ColorImageClass.cpp, project3
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains ColorImageClass's implementation.
//This class is for manipulating the things that
//will need to be add to an image

//Constructor
//Default constructor simply sets all pixels in the image to full black.
ColorImageClass::ColorImageClass(){
  colorClassArrayObjectPtr = 0;
}

//Make Base Image a class
bool ColorImageClass::initializeFromPpmFile(string ppmFileName){
  
  //count how many pixels
  int actualPixels;
  int expectedPixels;
  actualPixels = INIT_INPUT_PIXEL;
  
  //end of file indicator
  string eofIndicator;
  
  ifstream inFile;
  inFile.open(ppmFileName.c_str());
  
  if(inFile.fail()){
    cout << "Unable to open input file: " << ppmFileName << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  }
  
  //Assuming the first line is the magic number ("P3")
  inFile >> magicNumberInput;
  if(magicNumberInput != PPM_MAGIC_NUMBER){
    cout << "Not a valid PPM file: " << ppmFileName << endl;
    inFile.clear();
    inFile.ignore(LARGE_NUMBER, NEW_LINE);
    inFile.close();
    return INVALID_INPUT_INDICATOR;
  }
  
  //Read second line from the file
  inFile >> ppmWidth >> ppmHeight;
  
  //Check if width and height are valid (you might want to add more checks)
  if(ppmWidth <= MIN_PPM_WIDTH || ppmHeight <= MIN_PPM_WIDTH){
    cout << "Invalid width or height in PPM file: "
         << ppmFileName << endl;
    return INVALID_INPUT_INDICATOR;
  }
  
  expectedPixels = ppmWidth * ppmHeight;
  
  //read third line from the file
  inFile >> maxColorValueInput;
  
  //Check if max color value is 255
  if(maxColorValueInput > MAX_COLOR_VALUE ||
      maxColorValueInput < MIN_COLOR_VALUE){
    cout << "Invalid maximum color value in PPM file: " 
         << ppmFileName << endl;
    return INVALID_INPUT_INDICATOR;
  }
  
  //Allocate memory for the 2D dynamic array
  colorClassArrayObjectPtr = new ColorClass*[ppmHeight];
  for (int i = 0; i < ppmHeight; i++){
    colorClassArrayObjectPtr[i] = new ColorClass[ppmWidth];
  };
  
  //Read the pixel color values from the file and store in the dynamic array
  for(int i = 0; i < ppmHeight; i++) {
    for(int j = 0; j < ppmWidth; j++) {
      if (inFile.eof()) {
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
      ColorClass pixelColor;
      actualPixels++;
      if(!pixelColor.setColorFromPpm(inFile)){
        cout << "Found an out of range value when " 
             << "reading the image at row " << i
             << "col" << j;
        inFile.clear();
        inFile.ignore(LARGE_NUMBER, NEW_LINE);
        inFile.close();
        return INVALID_INPUT_INDICATOR;
      }
      else{
        colorClassArrayObjectPtr[i][j] = pixelColor;
      };
    }
  }
  
  //To see whether the pixels count is correct;
  if(actualPixels != expectedPixels) {
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
  }
};

//make Rectangle on the Base Image
void ColorImageClass::makeRectangleOnBaseImg(){
  //rec method variable
  int recMethod = INIT_VALUE;
  bool recMethodIndicator;
  //construct a default reectangle class
  RectangleClass recImg;
  string colorMethodChosen;
  
  //rec RowCol variable
  int recInUpLeftRow = INIT_VALUE;
  int recInUpLeftCol = INIT_VALUE;
  int recInLowRightRow = INIT_VALUE;
  int recInLowRightCol = INIT_VALUE;
  bool recRowColIndicator;
  
  //Guide users to put input
  cout << FIRST_REC_METHOD
       << ". Specify upper left and lower right corners of rectangle"
       << endl;
  cout << SECOND_REC_METHOD
       << ". Specify upper left corner and dimensions of rectangle"
       << endl;
  cout << THIRD_REC_METHOD
       << ". Specify extent from center of rectangle"
       << endl;
  
  cout << "Enter int for rectangle specification method: ";
  
  
  //check whether method input is correct
  recMethodIndicator = INVALID_REC_METHOD_INDICATOR;
  
  while(!recMethodIndicator){
    cin >> recMethod;
    if(cin.fail()){
      cout << "Rectangle Method Invalid, please enter a number between"
      <<  FIRST_REC_METHOD << " - " <<  THIRD_REC_METHOD << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      recMethodIndicator = INVALID_REC_METHOD_INDICATOR;
    }
    else if(recMethod > THIRD_REC_METHOD || recMethod < FIRST_REC_METHOD){
      cout << "Rectangle Method Invalid, please enter a number between"
      <<  FIRST_REC_METHOD << " - " <<  THIRD_REC_METHOD << "!";
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      recMethodIndicator = INVALID_REC_METHOD_INDICATOR;
    }
    else{
      recMethodIndicator = VALID_REC_METHOD_INDICATOR;
    }
  };
  
  //then will depends on different input to start
  //different rectangle create method
  
  //First Rec Method
  if(recMethod == FIRST_REC_METHOD){
    
    //// upper Left
    cout << "Enter upper left corner row and column: ";
    //check row and columne input
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> recInUpLeftRow >> recInUpLeftCol;
      //input fail
      if(cin.fail()){
        cout << "Row or column Invalid, "
             << "please enter two numbers that are in your base image!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(recInUpLeftRow > getHeight() || recInUpLeftRow < MIN_ROW_NUM
              || recInUpLeftCol > getWidth() || recInUpLeftCol < MIN_COL_NUM){
        cout << "Rectangle Row or Column Invalid, "
             << "please enter a row number between "
             << MIN_ROW_NUM << " - " <<  getHeight() << "!"
             << "Or a column number between "
             << MIN_COL_NUM << " - " <<  getWidth() << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }//end of make upperleft
    
    //// LowerRight
    cout << "Enter lower right corner row and column: ";
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> recInLowRightRow >> recInLowRightCol;
      //input fail
      if(cin.fail()){
        cout << "Row or column Invalid, "
             << "please enter two numbers that are in your base image!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(recInLowRightRow > getHeight() ||
              recInLowRightRow < recInUpLeftRow ||
              recInLowRightCol > getWidth() ||
              recInLowRightCol < recInUpLeftCol){
        cout << "Rectangle Row or Column Invalid, "
             << "please enter a row number between "
             << MIN_ROW_NUM << " - " <<  getHeight() << "!"
             << "Or a column number between "
             << MIN_COL_NUM << " - " <<  getWidth() << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }// end of make lower right
    
    //now we can create a Rectangle class
    //RectangleClass();
    recImg.setUpperLeft(recInUpLeftRow, recInUpLeftCol);
    recImg.setLowerRight(recInLowRightRow, recInLowRightCol);
  }//end of first method
  
  //second Rec Method
  else if(recMethod == SECOND_REC_METHOD){
    //for second and third method
    int inNumOfRows = INIT_VALUE;
    int inNumOfCols = INIT_VALUE;
    //// upper Left
    cout << "Enter upper left corner row and column: ";
    //check row and columne input
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> recInUpLeftRow >> recInUpLeftCol;
      //input fail
      if(cin.fail()){
        cout << "Row or column Invalid, "
             << "please enter two numbers that are in your base image!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(recInUpLeftRow > getHeight() || recInUpLeftRow < MIN_ROW_NUM
              || recInUpLeftCol > getWidth() || recInUpLeftCol < MIN_COL_NUM){
        cout << "Rectangle Row or Column Invalid, "
             << "please enter a row number between "
             << MIN_ROW_NUM << " - " <<  getHeight() << "!"
             << "Or a column number between "
             << MIN_COL_NUM << " - " <<  getWidth() << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }//end of make upperleft
    
    ////Number of Row (2)
    cout << "Enter int for number of rows: ";
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> inNumOfRows;
      //input fail
      if(cin.fail()){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_ROW_NUM << " - " << getHeight() - recInUpLeftRow << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(inNumOfRows > (getHeight() - recInUpLeftRow) ||
              inNumOfRows < MIN_ROW_NUM){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_ROW_NUM << " - " << getHeight() - recInUpLeftRow << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }// end of make Num of rows
    
    ////Number of Col (2)
    cout << "Enter int for number of cols: ";
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> inNumOfCols;
      //input fail
      if(cin.fail()){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_COL_NUM << " - " << getWidth() - recInUpLeftCol << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(inNumOfCols > (getWidth() - recInUpLeftCol) ||
              inNumOfCols < MIN_COL_NUM){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_COL_NUM << " - " << getWidth() - recInUpLeftCol << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }// end of make Num of rows
    
    //RectangleClass set;
    recImg.setUpperLeft(recInUpLeftRow, recInUpLeftCol);
    recImg.setLowerRight(recInUpLeftRow + inNumOfRows,
                         recInUpLeftCol + inNumOfCols);
  }//end of second method
  
  //third Rec Method
  else if(recMethod == THIRD_REC_METHOD){
    //a bool to know whether is upperleft
    int recInMidRow = INIT_VALUE;
    int recInMidCol = INIT_VALUE;
    int inHalfWidth = INIT_VALUE;
    int inHalfHeight = INIT_VALUE;
    //// upper Left
    cout << "Enter rectangle center row and column: ";
    //check row and columne input
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> recInMidRow >> recInMidCol;
      //input fail
      if(cin.fail()){
        cout << "Row or column Invalid, " 
             << "please enter two numbers that are in your base image!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(recInMidRow > getHeight() || recInMidRow < MIN_ROW_NUM
              || recInMidCol > getWidth() || recInMidCol < MIN_COL_NUM){
        cout << "Rectangle Row or Column Invalid, "
             << "please enter a row number between "
             << MIN_ROW_NUM << " - " <<  getHeight() << "!"
             << "Or a column number between "
             << MIN_COL_NUM << " - " <<  getWidth() << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }//end of make mid
    
    ////Number of Row (3)
    cout << "Enter int for half number of rows: ";
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> inHalfHeight;
      //input fail
      if(cin.fail()){
        cout << "Half Number of Rows Invalid,"
             << " please enter a row number between "
             << MIN_ROW_NUM << " - " << getHeight()/HALF << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(inHalfHeight > (getHeight()/HALF) ||
              inHalfHeight < MIN_ROW_NUM){
        cout << "Half Number of Rows Invalid,"
             << " please enter a row number between "
             << MIN_ROW_NUM << " - " << getHeight()/HALF << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }// end of make Num of rows
    
    ////Number of Col (3)
    cout << "Enter int for half number of cols: ";
    recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
    while(!recRowColIndicator){
      cin >> inHalfWidth;
      //input fail
      if(cin.fail()){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_COL_NUM << " - " << getWidth()/HALF << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      //input number fail
      else if(inHalfWidth > (getWidth()/HALF) ||
              inHalfWidth < MIN_COL_NUM){
        cout << "Number of Rows Invalid, please enter a row number between"
             << MIN_COL_NUM << " - " << getWidth()/HALF << "!";
        cin.clear();
        cin.ignore(LARGE_NUMBER, NEW_LINE);
        recRowColIndicator = INVALID_REC_ROW_COL_INDICATOR;
      }
      else{
        recRowColIndicator = VALID_REC_ROW_COL_INDICATOR;
      }
    }// end of make Num of rows
    
    //now we can create a Rectangle class
    //RectangleClass();
    recImg.setUpperLeft(recInMidRow - inHalfHeight,
                        recInMidCol - inHalfWidth);
    recImg.setLowerRight(recInMidRow + inHalfHeight,
                         recInMidCol + inHalfWidth);
  };//end of third method
  
  colorMethodChosen = COLOR_REC;
  //Choose Rectangle Color
  recImg.setRecColor(chooseColor(colorMethodChosen));
  
  //chooseFill is a function to see fill or not, then do the draw image things.
  if(chooseFill() == FILL){
    for(int i = recImg.getUpperLeft().getRow();
            i < recImg.getLowerRight().getRow();
            i++){
      for(int j = recImg.getUpperLeft().getCol();
              j < recImg.getLowerRight().getCol();
              j++){
        colorClassArrayObjectPtr[i][j].setTo(recImg.getRecColorClass());
      }
    }
  }
  else{
    for(int i = recImg.getUpperLeft().getRow();
            i < recImg.getLowerRight().getRow();
            i++){
      for(int j = recImg.getUpperLeft().getCol();
              j < recImg.getLowerRight().getCol();
              j++){
        if(i == recImg.getUpperLeft().getRow() ||
           i == (recImg.getLowerRight().getRow() - BOUNDARY) ||
           j == recImg.getUpperLeft().getCol() ||
           j == (recImg.getLowerRight().getCol() - BOUNDARY)){
          colorClassArrayObjectPtr[i][j].setTo(recImg.getRecColorClass());
        }
      }
    }
  };
  
};//end of makeRec function



//make Pattern on the Base Image
void ColorImageClass::makePatternOnBaseImg(){
  
  //start of set pattern file in ColorImage
  bool patternInputIndicator = INVALID_PATTERN_INPUT;
  string inputPatternFile;
  
  PatternClass patternInput;
  
  while(!patternInputIndicator){
    cout << "Enter string for file name containing pattern: ";
    cin >> inputPatternFile;
    
    if(!(patternInput.readPatternFile(inputPatternFile))){
      patternInputIndicator = INVALID_PATTERN_INPUT;
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
    }
    else{
      patternInputIndicator = VALID_PATTERN_INPUT;
    }
  }//end of set pattern file in ColorImage
  
  //start of set pattern location
  int patternRow = PAT_INIT_ROW;
  int patternCol = PAT_INIT_COL;
  patternInputIndicator = INVALID_PATTERN_INPUT;
  while(!patternInputIndicator){
    cout << "Enter upper left corner of pattern row and column: ";
    cin >> patternRow >> patternCol;
    //check upperleft location is the valid place
    if(patternRow < MIN_PAT_ROW ||
       patternRow > (getHeight() - patternInput.getPatternHeight()) ||
       patternCol < MIN_PAT_COL ||
       patternCol > (getWidth() - patternInput.getPatternWidth())){
      cout << "Enter a row number between " << MIN_PAT_ROW
           << " - " << (getHeight() - patternInput.getPatternHeight())
           << "Or a col number between " << MIN_PAT_COL
           << " - " << (getWidth() - patternInput.getPatternWidth());
      patternInputIndicator = INVALID_PATTERN_INPUT;
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
    }
    else{
      patternInput.setPatternLocation(patternRow, patternCol);
      patternInputIndicator = VALID_PATTERN_INPUT;
    }
  }//end of set pattern location
  
  //start of set pattern color
  string colorMethodChosen = COLOR_PATTERN;
  patternInput.setPatternColor(chooseColor(colorMethodChosen));
  //end of set pattern color
  
  //press pattern on the base image
  for(int i = 0; i < patternInput.getPatternHeight(); i++){
    for(int j = 0; j < patternInput.getPatternWidth(); j++){
      if(patternInput.getPatternPointer()[i][j] == PIXEL_IS_ONE){
        colorClassArrayObjectPtr
        [i + (patternInput. getPatternUpperLeft().getRow())]
        [j + (patternInput.getPatternUpperLeft().getCol())].
        setTo(patternInput.getPatternColor());
      }
    }
  }
  
};//end of pattern method

//insert Image on the base inage
bool ColorImageClass::insertImageOnBaseImg(){
  ColorImageClass insertedImage;
  bool imageInputIndicator = INVALID_IMAGE_INPUT;
  string inputImageFile;
  cout << "Enter string for file name of PPM image to insert:";
  cin >> inputImageFile;
  //use initial to fix duplicate code
  if(!insertedImage.initializeFromPpmFile(inputImageFile)){
    imageInputIndicator = INVALID_IMAGE_INPUT;
    return imageInputIndicator;
  };
  
  //already checked > 0, so just check < base
  if(insertedImage.getWidth() > ppmWidth ||
     insertedImage.getHeight() > ppmHeight){
    cout << "Invalid width or height in PPM file: " << inputImageFile
         << " Please has a file with Width > " << MIN_PPM_WIDTH << " and < "
         << ppmWidth << " or Height > " << MIN_PPM_WIDTH << " and < "
         << ppmHeight << endl;
    imageInputIndicator = INVALID_IMAGE_INPUT;
    return imageInputIndicator;
  }
  
  //start of set insert image location
  int insertImageRow = INSERT_IMG_INIT_ROW;
  int insertImageCol = INSERT_IMG_INIT_COL;
  imageInputIndicator = INVALID_INPUT_INDICATOR;
  while(!imageInputIndicator){
    cout << "Enter upper left corner to insert image row and column: ";
    cin >> insertImageRow >> insertImageCol;
    //check upperleft location is the valid place
    if(insertImageRow < INSERT_IMG_MIN_ROW ||
       insertImageRow > (getHeight() - insertedImage.getHeight()) ||
       insertImageCol < INSERT_IMG_MIN_COL ||
       insertImageCol > (getWidth() - insertedImage.getWidth())){
      cout << "Enter a row number between " << INSERT_IMG_MIN_ROW
           << " - " << (getHeight() - insertedImage.getHeight()) << endl
           << "Or a col number between " << INSERT_IMG_MIN_COL
           << " - " << (getWidth() - insertedImage.getWidth()) << endl;
      imageInputIndicator = INVALID_INPUT_INDICATOR;
      cin.clear();
      cin.ignore(LARGE_NUMBER, NEW_LINE);
      imageInputIndicator = INVALID_INPUT_INDICATOR;
    }
    else{
      imageInputIndicator = VALID_INPUT_INDICATOR;
    }
  } //end of set insert image location
  
  //start of choose trans color
  string colorMethodChosen = COLOR_TRANS;
  transColor.setTransColor(chooseColor(colorMethodChosen));
  //end of set insert image color
  
  //press image on the base image
  for(int i = 0; i < insertedImage.getHeight(); i++){
    for(int j = 0; j < insertedImage.getWidth(); j++){
      if(((insertedImage.colorClassArrayObjectPtr[i][j].getRedAmount()) !=
         (transColor.getRedAmount())) ||
         ((insertedImage.colorClassArrayObjectPtr[i][j].getGreenAmount()) !=
         (transColor.getGreenAmount())) ||
         ((insertedImage.colorClassArrayObjectPtr[i][j].getBlueAmount()) !=
         (transColor.getBlueAmount()))){
        colorClassArrayObjectPtr[(i + insertImageRow)]
                                [(j + insertImageCol)].
        setTo(insertedImage.colorClassArrayObjectPtr[i][j]);
      }
    }
  }
  imageInputIndicator = VALID_INPUT_INDICATOR;
  return imageInputIndicator;
};


//4. Write out image
void ColorImageClass::writeOutImg(string outputName){
  ofstream outFile;
  
  outFile.open(outputName.c_str());
  if(outFile.fail()){
    cout << "Can't open output file" << endl;
  }
  else{
    outFile << magicNumberInput << endl;
    outFile << ppmWidth << " ";
    outFile << ppmHeight << endl;
    outFile << maxColorValueInput << endl;

    for(int i = 0; i < ppmHeight; i++){
      for(int j = 0; j < ppmWidth; j++){
        outFile << colorClassArrayObjectPtr[i][j].writeColor();
      }
    }
  }
  outFile.close();
};


//get color image class width
int ColorImageClass::getWidth(){
  return ppmWidth;
};

//get color image class height
int ColorImageClass::getHeight(){
  return ppmHeight;
};

int ColorImageClass::getMaxColorInput(){
  return maxColorValueInput;
}

string ColorImageClass::getMagicNumber(){
  return magicNumberInput;
};

int ColorImageClass::getTransRed(){
  return transColor.getRedAmount();
}

int ColorImageClass::getTransGreen(){
  return transColor.getGreenAmount();
}

int ColorImageClass::getTransBlue(){
  return transColor.getBlueAmount();
}
