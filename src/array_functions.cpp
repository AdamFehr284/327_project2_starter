/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Adam Fehr
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "array_functions.h"
//============================================================================
//	stuff you will need
//============================================================================
using namespace std;


//TODO define a structure to track words and number of times they occur
struct entry{
	string word;
	int number_occurences;
};

//TODO add a global array of entry structs (global to this file)
entry fileEntries [1];

//TODO add variable to keep track of next available slot in array
int nextAvailable = 0;

//TODO define all functions in header file
void clearArray(){

}

int getArraySize(){
	return (sizeof(fileEntries)/sizeof(*fileEntries));
}

std::string getArrayWordAt(int i){
	return fileEntries[i].word;
}

int getArrayWord_NumbOccur_At(int i){
	return fileEntries[i].number_occurences;
}

bool processFile(std::fstream &myfstream){

	string str;

	if(!myfstream.is_open()){
		return false;
	}
	while(getline(myfstream, str)){
		processLine(str);
	}

	return true;
}

bool openFile(std::fstream& myfile, const string& myFileName,
		std::ios_base::openmode mode){

	myfile.open(myFileName.c_str(), ios::in);

	if(myfile.is_open()){
		return true;
	}
	else {
		return false;
	}
}

void processLine(std::string &myString){

}

void processToken(std::string &token){

}



void closeFile(std::fstream& myfile){
	myfile.close();
}

int writeArraytoFile(const std::string &outputfilename){
	return 1;
}

void sortArray(constants::sortOrder so){

}






//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

