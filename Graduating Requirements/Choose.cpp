#include <iostream>
#include <stdlib.h>
#include "Choose.h"
#include <string>

using namespace std;

int Choose::getNum()
{
	return numNeeded;
}

void Choose::setNum(string num)
{
	numNeeded = stoi(num);
}

void Choose::addToVec(string c)
{
	course.push_back(c);
}

void Choose::printVec()
{
	for(int i=0; i < course.size(); i++)
	{
		cout << course[i] << " ";
	}

	cout << endl;
}

bool Choose::check(vector<string> classes)
{
	int counter = 0;
	for(int i = 0; i < classes.size(); i++){

		for(int j = 0; j < course.size(); j++){

			if(classes[i] == course[j]){

				counter++;

			}
		}

	}

	if(counter >= numNeeded){ return true; }
	return false;

}
