#ifndef constant_h
#define constant_h

#include <iostream>
#include <string>

using namespace std;

//project3 constant.h
//Programmer: Tzu-Yu Peng, typeng
//Date: October 21st 2023
//This file contains constants that will be used by project3.

//constant declarations and initializations of Color things
const int INIT_COLOR_VALUE = 255;
const int MAX_COLOR_VALUE = 255;
const int MIN_COLOR_VALUE = 0;


//This is the default row and column numbers.
const int DEFAULT_ROW_COL = -99999;


//These are the min row and column numbers.
const int MIN_ROW_NUM = 0;
const int MIN_COL_NUM = 0;


//to know when to print -- we need to know whether it is the last one
//const int MAX_COL_NUM_FOR_PRINT = MAX_COL_NUM - 1;
const int INIT_INPUT_PIXEL = 0;

//cin stuff
const int LARGE_NUMBER = 200;
const char NEW_LINE = '\n';

//whichAction
const int ANNOTATE_RECTANGLE = 1;
const int ANNOTATE_PATTERN = 2;
const int INSERT_IMAGE = 3;
const int WRITE_OUT = 4;
const int EXIT_PROGRAM = 5;

//ppmMagicNumber
const string PPM_MAGIC_NUMBER = "P3";


//Input
const int MIN_PPM_WIDTH = 0;
const int MIN_PPM_HEIGHT = 0;

const bool INVALID_INPUT_INDICATOR = false;
const bool VALID_INPUT_INDICATOR = true;

//color method option
const int RED_OPTION = 1;
const int GREEN_OPTION = 2;
const int BLUE_OPTION = 3;
const int BLACK_OPTION = 4;
const int WHITE_OPTION = 5;

//color applied place
const string COLOR_REC = "COLOR_REC";
const string COLOR_PATTERN = "COLOR_PATTERN";
const string COLOR_TRANS = "COLOR_TRANS";

const bool INVALID_COLOR_INDICATOR = false;
const bool VALID_COLOR_INDICATOR = true;


//rectangleMethod
const int INIT_VALUE = -1;
const int FIRST_REC_METHOD = 1;
const int SECOND_REC_METHOD = 2;
const int THIRD_REC_METHOD = 3;

const bool INVALID_REC_METHOD_INDICATOR = false;
const bool VALID_REC_METHOD_INDICATOR = true;

const bool INVALID_REC_ROW_COL_INDICATOR = false;
const bool VALID_REC_ROW_COL_INDICATOR = true;

const bool UPPER_LEFT = true;
const bool NOT_UPPER_LEFT = false;

const int HALF = 2;

const int BOUNDARY = 1;


//Fill or NOT
const int NOT_FILL = 1;
const int FILL = 2;

const bool VALID_FILL = true;
const bool INVALID_FILL = false;


//PatternMethod
const int PAT_INIT_WIDTH = -1;
const int PAT_INIT_HEIGHT = -1;

const int MIN_PAT_WIDTH = 0;
const int MIN_PAT_HEIGHT = 0;

const bool INVALID_PATTERN_INPUT = false;
const bool VALID_PATTERN_INPUT = true;

const int PAT_INIT_ROW = -1;
const int PAT_INIT_COL = -1;

const int MIN_PAT_ROW = 0;
const int MIN_PAT_COL = 0;

const int PIXEL_IS_ONE = 1;
const int PIXEL_IS_ZERO = 0;


//Image
const bool INVALID_IMAGE_INPUT = false;
const bool VALID_IMAGE_INPUT = true;

const int INIT_INSERT_IMAGE_WIDTH = -1;
const int INIT_INSERT_IMAGE_HEIGHT = -1;

const int INSERT_IMG_INIT_ROW = -1;
const int INSERT_IMG_INIT_COL = -1;

const int INSERT_IMG_MIN_ROW = 0;
const int INSERT_IMG_MIN_COL = 0;

#endif /* constant_h */
