#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include "Credit.h"
#include <vector>
#include "Course.h"
#include <unordered_map>
#include "Choose.h"
#include "string_graph.h"
#include "mycoursenode.cpp"

using namespace std;

int main(int argc, char *argv[]){

	int creditTotal = 0;
	int errorCount = 0;

	string reqFile = argv[1];
	string offFile = argv[2];
	string scheduleFile = argv[3];
	Credit neededTotalCredits;

	string line;
	string keyword;
	string val;
	string val1;
	string val2;
	string val3;
	int total;
	int i = 0;
	vector<Credit*> credits;
	unordered_map<string, Course> courseOfferings;

	vector<Choose> chosenCourses;

	int graphsize=0;
	vector<string> requirecourses;//the vector of requirecourses
	vector<string> mandatorycourses; //M courses
	vector<mycoursenode*> mycourses;//the vector of courses node object that used to build a graph
	vector<string> coursenames;//the vector of courses name

	//Reading information from the requirement file
	
	ifstream rFile(reqFile);
	if (rFile.is_open()){
    	while (getline(rFile,line)){
			
			stringstream iss(line);
			while(iss >> keyword){							
				if(keyword == "TOTAL"){
					
					iss >> val;
					neededTotalCredits.setName(keyword);
					neededTotalCredits.setNumber(val);

				}else if(keyword == "CREDIT"){ 
				
					iss >> val;
					iss >> val1;
					Credit *neededCredits = new Credit(val, val1);
					credits.push_back(neededCredits);
					i++;	
					
				}else if(keyword == "COURSE"){ 
				
					string coursename;
					vector<string> r;
					vector<string> courseVector;
					graphsize++;
					
					while(iss >> val){
						
						courseVector.push_back(val);
						
					}
					
					coursename = courseVector[0];
					coursenames.push_back(coursename);
					
					if(courseVector[1] == "R"){ requirecourses.push_back(courseVector[0]); }
					if(courseVector[1] == "M"){ mandatorycourses.push_back(courseVector[0]); }
					
					for(int i=2;i<courseVector.size();i++){
						r.push_back(courseVector[i]);
					}
					mycoursenode *mycourse = new mycoursenode(coursename,r);
					mycourses.push_back(mycourse);
					
				}else if(keyword == "CHOOSE"){
					i = 0;
					Choose c;
					while(iss >> val){
						if(i == 0){
							c.setNum(val);	
						}
						else if(i > 0){
							c.addToVec(val);
						}
						i++;
					}
					chosenCourses.push_back(c);
				}
			}			
    	}
    	
		rFile.close();

	}
	
	//initializing prerequisite graph

	coursegraph *mygraph = new coursegraph(graphsize,coursenames);
	for(int i=0;i<mycourses.size();i++)
	{
		for(int j=0;j<((mycourses[i]->requirecourse).size());j++)
			mygraph->addEdge(mycourses[i]->coursename,((mycourses[i]->requirecourse)[j]));
	}
	
	//Reading information from offerings file

	ifstream oFile(offFile);
	if (oFile.is_open()){

    		while ( getline (oFile,line) ){

			stringstream iiss(line);
		
			vector<string> courseCredits;
			while(iiss >> val)
			{
				courseCredits.push_back(val);
			}

			if(courseCredits.size() == 4)
			{
				Course offCourses(courseCredits[1], courseCredits[2], courseCredits[3]);
				courseOfferings.insert({courseCredits[0], offCourses});
			}
			else
			{
				Course offCourses(courseCredits[1], courseCredits[2], "");
				courseOfferings.insert({courseCredits[0], offCourses});
			}

			
	
		}

    		oFile.close();

	}
	
	//Reading schedule

	vector<string> semesters;

	ifstream sFile(scheduleFile);
	int year1;
	int year2;

	if (sFile.is_open()){
		
		//push all lines of file into a vector for sorting

		while (getline (sFile,line)){ semesters.push_back(line); }
		
		//bubble-sort semesters to be in proper order

		for (auto j=semesters.end(); j != semesters.begin(); --j) {

			for (auto i = semesters.begin() + 1; i != j; ++i) {

		    	auto& semester1 = *i;
		    	auto& semester2 = *(i - 1);

				year2 = stoi(semester1.substr(1, -1));
				year1 = stoi(semester2.substr(1, -1));

				if(semester1 > semester2){

					if(year1 > year2){ swap(semester1, semester2);}

				}else if(semester1 < semester2){

					if(year1 != year2){ swap(semester1, semester2);}

		    		}
				}
    		}

		sFile.close();
	
	}
	
	//writing the sorted vector onto the schedule file

	ofstream sWrite(scheduleFile);
	if(sWrite.is_open()){

		for(int i = 0; i < semesters.size(); i++){

			sWrite << semesters[i] << endl;
		
		}


		sWrite.close();

	}
	
	//all checks for issues in the schedule

	string item;
	vector<string> takenClasses;
	int chooseCourseCount = 0;

	ifstream schFile(scheduleFile);

	if (schFile.is_open()){

    		while (getline (schFile,line)){

			//string *classArr = new string[5];
			vector<string> classes;

			stringstream x(line);
			
			//work with one line at a time

			while(x >> item){
	
				classes.push_back(item);

			}

				string courseTime;
				string offeringTime;
				vector<char> classSecondaryCredits;
				string prereq;
				for(int i = 1; i < classes.size(); i++){

					try{

						courseOfferings.at(classes[i]).getCredits(); //ensures the class is in the offerings map
				
						//Check class for prerequisites
				
						takenClasses.push_back(classes[i]);
						prereq = mygraph->getrequire(classes[i]);
						
						bool taken;
						if(find(takenClasses.begin(), takenClasses.end(), prereq) != takenClasses.end() && prereq != " "){

							if(find(classes.begin(), classes.end(), prereq) != classes.end()){
							
								taken = false;

							}else{ taken = true; }

						}else{ taken = false; }

						if(!taken && prereq != " "){ 
							

							cout << "Bad Plan: " << classes[i] << " requires a prerequisite of " << prereq << endl;
							errorCount++;
							return 0;

						}

						//Check class is being taken during a proper semester

						courseTime = courseOfferings.at(classes[i]).getOfferingTime().substr(0);

						offeringTime = classes[0][0];

						if(courseTime != offeringTime && courseTime != "E"){ 
							cout << "Bad Plan: " << classes[i] << " is not offered during " << classes[0] << endl;
							errorCount++;
							return 0;

						}else{

							//Add credits of each class being taken in the proper sequence
							creditTotal += courseOfferings.at(classes[i]).getCredits();

						}


					}catch(...){
						
						//Catch any class not in the offerings file

						cout << "Bad plan: " << classes[i] << " is not a registered class." << endl;
						errorCount++;
						return 0;


					}

					try{
						
						//Check that all secondary-credit requirements are fulfilled

						if(courseOfferings.at(classes[i]).getCheck()){					

							classSecondaryCredits = courseOfferings.at(classes[i]).getSecondary();

							for(int j = 0; j < credits.size(); j++){
				
								for(int k = 0; k < classSecondaryCredits.size(); k++){						

									stringstream casting;
									string target;
									char mychar = classSecondaryCredits[k];
			
									casting << mychar;
									casting >> target;
		
									if(credits[j]->getName() == target){
		
										credits[j]->increment(courseOfferings.at(classes[i]).getCredits());

									}

								}

							}

						}

					}catch(...){}


				}

    	
    	}
		
		//Check that all CHOOSE options were fulfilled
		
		int tot = 0;
		int i;
		for(i = 0; i < chosenCourses.size(); i++){

			if(chosenCourses[i].check(takenClasses)){ tot++; }
			else{ break; }
	
		}

		if(tot != chosenCourses.size()){ cout << "Bad Plan: Must take " << chosenCourses[i].getNum() << " class from list of: "; chosenCourses[i].printVec(); return 0; }
		
		//Check that all R classes were taken

		bool val = true;
		vector<string> notTaken;
		for(int i = 0; i < takenClasses.size(); i++){

			for(int j = 0; j < requirecourses.size(); j++){
				
				if(find(takenClasses.begin(), takenClasses.end(), requirecourses[j]) == takenClasses.end()){
					val = false;
					if(find(notTaken.begin(), notTaken.end(), requirecourses[j]) == notTaken.end()){ notTaken.push_back(requirecourses[j]); }

				}
				
			}
			for(int j = 0; j < mandatorycourses.size(); j++){
				
				if(find(takenClasses.begin(), takenClasses.end(), mandatorycourses[j]) == takenClasses.end()){
					val = false;
					if(find(notTaken.begin(), notTaken.end(), mandatorycourses[j]) == notTaken.end()){ notTaken.push_back(mandatorycourses[j]); }

				}
				
			}
		}

		if(!val){
			cout << "Bad Plan: The following required or mandatory courses haven't been taken: ";
			for(int i = 0; i < notTaken.size(); i++){ cout << notTaken[i] <<  " "; }
			errorCount++;
			cout << endl;
			return 0;
		}

		//Check if total credits taken meets the designated total
		
		if(creditTotal < neededTotalCredits.getNumber()){
			cout << "Bad Plan: Only " << creditTotal << " credits taken. A total of " << neededTotalCredits.getNumber() << " is needed" << endl;
			errorCount++;
			return 0;


		}

		//Check if each secondary credit total meets the designated amount
		
		for(int i = 0; i < credits.size(); i++){

			if(credits[i]->getNumber() > credits[i]->getRunningTotal()){
				cout << "Bad Plan: Only " << credits[i]->getRunningTotal() << " credits taken for " << credits[i]->getName() << " requirement instead of " << credits[i]->getNumber() << endl;
				errorCount++;
				return 0;
			}

		}

		schFile.close();
	
	}
	
	//Check for any previously caught problems with the schedule

	if(errorCount == 0){ cout << "Good Plan! Get to work" << endl; }

	return 0;

}


