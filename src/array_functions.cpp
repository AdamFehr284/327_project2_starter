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

int arrLength = 1;

//TODO add a global array of entry structs (global to this file)
entry* fileEntries  = new entry[arrLength];

//TODO add variable to keep track of next available slot in array
int nextAvailable = 0;

//TODO define all functions in header file
void clearArray(){

}

int getArraySize(){
	return arrLength;
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

	return myfile.is_open();
}

void extractTokensFromLine(std::string &myString) {
	stringstream ss(myString);
	string tempToken;

	while(getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}
}

void processLine(std::string &myString){

	stringstream ss(myString);
		string tempToken;

		while(getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)){
			processToken(tempToken);
		}
}

void processToken(std::string &token){
	if(nextAvailable == arrLength){

		entry* bigger_arr = new entry[arrLength ];

		for(int i = 0; i < arrLength; i++){
			bigger_arr[i] = fileEntries[i];
		}

		arrLength++;
		delete [] fileEntries;
		fileEntries = bigger_arr;
	}

	bool added = false;

	for(int x = 0; x < arrLength; x++){
		if(token == fileEntries[x].word){
			fileEntries[x].number_occurences ++;
			added = true;
			break;

		}
	}
	if(!added){
		fileEntries[nextAvailable].word = token;
		fileEntries[nextAvailable].number_occurences = 1;
		nextAvailable++;
	}

}



void closeFile(std::fstream& myfile){
	myfile.close();
}

int writeArraytoFile(const std::string &outputfilename){
	return 1;
}

void sortArray(constants::sortOrder so){

	string tempWord;
	int tempOccurences;

	for (int i = 0; i < arrLength; ++i)
	{
	    for (int j = i + 1; j < arrLength; ++j)
	    {
	    	if (fileEntries[i].word > fileEntries[j].word)
	    	            {
	    	                tempWord =  fileEntries[i].word;
	    	                tempOccurences = fileEntries[i].number_occurences;

	    	                fileEntries[i].word = fileEntries[j].word;
	    	                fileEntries[i].number_occurences = fileEntries[j].number_occurences;

	    	                fileEntries[j].word = tempWord;
	    	                fileEntries[j].number_occurences = tempOccurences;
	    	            }
	    }
	}
}






//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

