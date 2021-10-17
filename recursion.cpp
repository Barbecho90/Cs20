#include <iomanip>
#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
#include <iostream>


using namespace std;

void reversed(string str, int &punctuationCount, bool printReverse )
{
	if(str.size()==0)
	{
		return;
	}
	reversed(str.substr(1), punctuationCount, printReverse);
		
	if(printReverse){
		cout << str[0];
	}
	
	if(!isalnum(str[0]) && str[0] != ' ' && str[0] != '\n')
	{
		punctuationCount++;
	}
}

void readMyFile(fstream &file, int &punctuationCount , bool printReverse){
	if(file.eof()){
		return;
	}
	string line;
	getline(file, line);
	line = '\n' + line;
	readMyFile(file, punctuationCount, printReverse);
	reversed(line, punctuationCount, printReverse);
}


int main()
{
	int options = -1;
	//Print Options
	while(options !=0){
		cout << endl << endl << "Enter" << endl;
		cout << "[1] to find the number of puntuation marks in the story"<< endl;
		cout << "[2] to print the story in reverse"<< endl;
		cout << "[3] for Both"<< endl;
		cout << " Option: " ;
		cin >> options ;
		bool printReverse, printCount = false;
		int punctuationCount=0;

		if(options ==1){
			printCount=true;
		}
		else if(options==2){
			printReverse=true;
		}
		else if(options==3){
			printReverse=true;
			printCount=true;
		}

		fstream file;
		file.open("Recursion.txt");
		if(!file.is_open()) {
			cout << "File is not open" << endl; 
		}

		readMyFile(file, punctuationCount, printReverse);
		if(printCount){
			cout << endl << "Number of punctuation marks: " << punctuationCount << endl << endl;
		}

		file.close();
	}

	return 0;
}
