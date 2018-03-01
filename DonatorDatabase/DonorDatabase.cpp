#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "DonorDatabase.h"
using namespace std;

DonorDatabase::DonorDatabase(int numDonors){

	arrSize = numDonors;
	donorArray = new Donor[arrSize];

}

void DonorDatabase::addElement(Donor newDonor){

	if(index >= arrSize){
		cout << "Error! Not Enough Space to store new Donor." << endl;
	}else{
		newDonor.add();
		for(int i = 0; i < arrSize; i++){

			while(true){
				if(newDonor.getUserID() == donorArray[i].getUserID()){

					cout << "Error: Username Taken" << endl;
					string id = "";
					cout << "New Username: ";
					cin >> id;
					newDonor.checkUserID(id);

				}else{ break; }
			}

		}
		donorArray[index] = newDonor;
		index++;
	}

}

bool DonorDatabase::login(string userid){
	
	int length = sizeof(donorArray);

	for(int i = 0; i < length; i++){

		if(donorArray[i].getUserID() == userid){

			string pass = "";
			cout << "Enter Password: ";
			cin >> pass;
			if(donorArray[i].getPassword() == pass){ 
				int x = donorArray[i].secondMenu();
				mainMenu();
			}else{ return false; }
		}
	
	}

	return false;

}

void DonorDatabase::save(){

	string fileName = "";
	cout << "Enter File Name: ";
	cin >> fileName;

	while(true){

		ifstream infile(fileName, std::ofstream::app);
		if(!infile.good()){

			string choice = "";
			cout << "Would you Like to Overwrite This File['Yes' 'No']: ";
			cin >> choice;
			if(choice == "Yes"){ break; }
			else if(choice == "No") { cout << "Enter File Name: "; cin >> fileName; }
			else{ cout << "Enter Valid Choice"; }
			
		}else{ break; }
	}
	ofstream file;
	file.open(fileName, std::ios_base::app);

	for(int i = 0; i < index; i++){

		file << donorArray[i].getFirstName() << endl;
		file << donorArray[i].getLastName() << endl;
		file << donorArray[i].getUserID() << endl;
		file << donorArray[i].getPassword() << endl;
		file << donorArray[i].getAge() << endl;
		file << donorArray[i].getStreetNum() << endl;
		file << donorArray[i].getStreetName() << endl;
		file << donorArray[i].getTownName() << endl;
		file << donorArray[i].getState() << endl;
		file << donorArray[i].getZip() << endl;
		file.precision(2);
		file << fixed << donorArray[i].getTotal() << endl;

	}

	file.close();

}

void DonorDatabase::load(string fileName){

	int x = 0;
	int i = 1;
	ifstream newFile;
	string output = "";
	newFile.open(fileName);

	while(getline(newFile, output)){

		if(i == 1){ donorArray[x].checkFirst(output);}
		else if(i == 2){ donorArray[x].checkLast(output);}
		else if(i == 3){ donorArray[x].checkUserID(output);}
		else if(i == 4){ donorArray[x].checkPassword(output);}
		else if(i == 5){ donorArray[x].checkAge(output);}
		else if(i == 6){ donorArray[x].checkStreetNumber(output);}
		else if(i == 7){ donorArray[x].checkStreetName(output);}
		else if(i == 8){ donorArray[x].checkTownName(output);}
		else if(i == 9){ donorArray[x].checkState(output);}
		else if(i == 10){ donorArray[x].checkZip(output);}
		else if(i == 11){ donorArray[x].checkDonation(output); }
		
		i++;
		if(i > 11){ i = 1; x++; };

		if(x > arrSize){
			
			cout << "Error: Too Many Donors. Max Possible Were Recorded" << endl;
			break;

		}

	}

	index = x;
	
	newFile.close();

}

void DonorDatabase::report(){

	float tot = 0;

	for(int i = 0; i < arrSize; i++){

		tot += donorArray[i].getTotal();

	}

	cout.precision(2);
	cout << fixed << "There are " << arrSize << " Donors with a total of $" << tot << endl;

}

void DonorDatabase::mainMenu(){
	
	while(true){

		cout << "Enter a Command" << endl;
		cout << "Choose from ['Login' 'Add' 'Save' 'Load' 'Report' 'Quit']" << endl;
		string input = "";
		cout << ":";
		cin >> input;
		
	
		if(input == "Login"){

			
			while(true){
				string user;
				cout << "Enter Username: ";
				cin >> user;
				bool donorExists = login(user);
				if(!donorExists){ 
					cout << "Error! Wrong Username/Password." << endl;
				} 
			}
			
			
		}else if(input == "Add"){

			Donor newDonor;
			addElement(newDonor);

		}else if(input == "Save"){

			save();

		}else if(input == "Load"){

			string fileName = "";
			cout << "Enter File Name: ";
			cin >> fileName;
			load(fileName);

		}else if(input == "Report"){

			report();

		}else if(input == "Quit"){
			
			while(true){
				
				string choice = "";
				cout << "Would You Like to Save ['Yes' 'No']: ";
				cin >> choice;
				if(choice == "Yes"){ save(); break; }
				else if(choice == "No"){ break; }
				else{ cout << "Enter Valid Choice" << endl; }

			}

			break;

		}else{
			
			cout << "Command not recognized. Please try again." << endl;

		}

	}
	
}

DonorDatabase::~DonorDatabase(){}
