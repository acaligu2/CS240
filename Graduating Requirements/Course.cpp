#include "Course.h"

Course::Course(string credit, string offering){

	credits = stoi(credit);
	offeringTime = offering;
	secondaryCheck = false;

}
Course::Course(string credit, string offering, string type){

	credits = stoi(credit);
	offeringTime = offering;
	if(type != ""){
		for (char & c : type)
		{
			secondary.push_back(c);
		}
		secondaryCheck = true;
	}

}

int Course::getCredits(){ return credits; }

string Course::getOfferingTime(){ return offeringTime; }

void Course::setCredits(int c){ credits = c; }

void Course::setOffering(string o){ offeringTime = o; }

void Course::setReqs(string s){

	reqs.push_back(s);

}

vector<string> Course::getReqs(){ return reqs; }

bool Course::getCheck(){ return secondaryCheck; }

vector<char> Course::getSecondary(){ return secondary; }
