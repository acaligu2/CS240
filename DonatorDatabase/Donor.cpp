#include "Donor.h"

Donor::Donor(){

	string lastName = "";
	string firstName = "";
	string userid = "";
	string password = "";
	int age = 0;
	int streetNumber = 0;
	string streetName = "";
	string townName = "";
	string zipCode = "";
	string state = "";
	float donationAmt = 0;
	float totalAmt = 0;
	states st = NY;
	string sString = "";

}

void Donor::checkFirst(string fn){
	
	while(true){
		bool fResult = isString(fn);
		if(!fResult){
			cout << "Error! Enter Proper First Name: ";
			cin >> fn;
			bool fResult = isString(fn);
		}else{
			break;
		}

	}

	firstName = fn;

}

void Donor::checkLast(string ln){

	while(true){
		bool lResult = isString(ln);
		if(!lResult){
			cout << "Error! Enter Proper Last Name: ";
			cin >> ln;
			bool fResult = isString(ln);
		}else{
			break;
		}
	}

	lastName = ln;

}

void Donor::checkUserID(string id){

	while(true){
		if(id.size() >= 5 && id.size() <= 10){
			bool uResult = isAlphaNumeric(id);
			if(!uResult){
				cout << "Error! Enter Valid Userid: ";
				cin >> id;
				bool uResult = isAlphaNumeric(id);
			}else{ break; }
		}else{
			cout << "Error! Enter Valid Userid: ";
			cin >> id;
		}
	}

	userid = id;

}

void Donor::checkPassword(string pass){

	while(true){
		if(pass.size() >= 6){
			bool pResult = containsSpecialChar(pass);
			if(!pResult){
				cout << "Error! Enter Valid Password: ";
				cin >> pass;
				bool pResult = containsSpecialChar(pass);
			}else{ break; }
		}else{ 
			cout << "Error! Enter Valid Password: ";
			cin >> pass;
		}
	}

	password = pass;

}

void Donor::checkAge(string aInput){

	int a = 0;
	while(true){
		bool aResult = isNum(aInput);
		if(aResult){
			a = stoi(aInput);
			if(a >= 18){ break; }
			else{ 
				cout << "Error! Enter Valid Age: ";
				cin >> aInput;
			}
		}else{ 
			cout << "Error! Enter Valid Age: ";
			cin >> aInput;
			bool aResult = isNum(aInput);
		}
	}

	age = a;

}

void Donor::checkStreetNumber(string sNum){

	int streetNum = 0;
	while(true){
		bool snResult = isNum(sNum);
		if(snResult){
			streetNum = stoi(sNum);
			if(streetNum > 0){ break; }
			else{ 
				cout << "Error! Enter Valid House Number: ";
				cin >> sNum;
			}
		}else{ 
			cout << "Error! Enter Valid House Number: ";
			cin >> sNum;
			bool snResult = isNum(sNum);
		}
	}
	
	streetNumber = streetNum;

}

void Donor::checkStreetName(string sn){

	while(true){
		bool sResult = isValidString(sn);
		if(!sResult){
			cout << "Error! Enter Proper Street Name: ";
			getline(cin, sn);
			bool sResult = isValidString(sn);
		}else{
			break;
		}
	}
	streetName = sn;

}

void Donor::checkTownName(string t){

	while(true){
		bool tResult = isValidString(t);
		if(!tResult){
			cout << "Error! Enter Proper Town Name: ";
			cin >> t;
			bool tResult = isValidString(t);
		}else{
			break;
		}
	}
	townName = t;

}

void Donor::checkZip(string zInput){

	while(true){
		bool zResult = isNum(zInput);
		if(zResult){
			if(zInput.size() == 5){ break; }
			else{ 
				cout << "Error! Enter Valid Zip Code: ";
				cin >> zInput;
			}
		}else{ 
			cout << "Error! Enter Valid Zip Code: ";
			cin >> zInput;
			bool zResult = isNum(zInput);
		}
	}
	zipCode = zInput;

}

void Donor::checkState(string s){

	while(true){

		if(s == "NY"){ state = NY; sString = "NY"; break; }
		else if(s == "PA"){ state = PA; sString = "PA"; break;}
		else if(s == "RI"){ state = RI; sString = "RI"; break;}
		else if(s == "NH"){ state = NH; sString = "NH"; break;}
		else if(s == "VT"){ state = VT; sString = "VT"; break;}
		else if(s == "MA"){ state = MA; sString = "MA"; break;}
		else if(s == "CT"){ state = CT; sString = "CT"; break;}
		else if(s == "ME"){ state = ME; sString = "ME"; break;}
		else{

			cout << "Error! Enter Valid State: ";
			cin >> s;

		}

	}

}

void Donor::checkDonation(string s){

	float amt = 0.0;
	while(true){
		try{ amt = stof(s); }
		catch(exception& e){ 

			cout << "Enter Valid Donation: ";
			cin >> s;
	
		}
		
		break;

	}

	donate(amt);

}

void Donor::add(){

	string fn = "";
	cout << "First Name: ";
	cin >> fn;
	checkFirst(fn);

	string ln = "";
	cout << "Last Name: ";
	cin >> ln;
	checkLast(ln);

	string id = "";
	cout << "Username: ";
	cin >> id;
	checkUserID(id);

	string pass = "";
	cout << "Password: ";
	cin >> pass;
	checkPassword(pass);
	
	string a = "";
	cout << "Age: ";
	cin >> a;
	checkAge(a);

	string sNum = "";
	cout << "House Number: ";
	cin >> sNum;
	checkStreetNumber(sNum);

	string sn = "";
	cout << "Street Name: ";
	cin.ignore();
	getline(cin, sn);
	checkStreetName(sn);
	
	string t = "";
	cout << "Town: ";
	getline(cin, t);
	checkTownName(t);

	string s = "";
	cout << "State: ";
	cin >> s;
	checkState(s);
	
	string zip = "";
	cout << "Zip Code: ";
	cin >> zip;
	checkZip(zip);

}

void Donor::manage(){

	while(true){
		string option = "";
		cout << "Enter Field to Change" << endl;
		cout << "Choose from ['First' 'Last' 'Age' 'House' 'Street' 'Town' 'Zip' 'Quit']" << 				endl;
		cout << ":";
		cin >> option;
		
		if(option == "First"){ 
		
			string fn = "";
			cout << "First Name: ";
			cin >> fn;
			checkFirst(fn);

		}else if(option == "Last"){
			
			string ln = "";
			cout << "Last Name: ";
			cin >> ln;
			checkLast(ln);

		}else if(option == "Age"){
			
			string a = "";
			cout << "Age: ";
			cin >> a;
			checkAge(a);


		}else if(option == "House"){
			
			string sNum = "";
			cout << "House Number: ";
			cin >> sNum;
			checkStreetNumber(sNum);
			
		}else if(option == "Street"){
			
			string sn = "";
			cout << "Street Name: ";
			cin.ignore();
			getline(cin, sn);
			checkStreetName(sn);

		}else if(option == "Town"){
			
			string t = "";
			cout << "Town: ";
			cin.ignore();
			getline(cin, t);
			checkTownName(t);

		}else if(option == "Zip"){
			
			string zip = "";
			cout << "Zip Code: ";
			cin >> zip;
			checkZip(zip);

		}else if(option == "State"){
				
			string s = "";
			cout << "State: ";
			cin >> s;
			checkState(s);	

		}else if(option == "Quit"){
			
			break;
		
		}else{ cout << "Error! Enter Valid Command!" << endl; }
		
	}
}

void Donor::newPass(){

	while(true){
		string oldPassword = "";
		cout << "Enter Old Password: ";
		cin >> oldPassword;
		if(oldPassword != password){
			cout << "Invalid Password" << endl;
		}else{ break; }
	}

	string newPass = "";
	cout << "Enter New Password: ";
	cin >> newPass;
	while(true){
		if(newPass.size() >= 6){
			bool pResult = containsSpecialChar(newPass);
			if(!pResult){
				cout << "Error! Enter Valid Password: ";
				cin >> newPass;
				bool pResult = containsSpecialChar(newPass);
			}else{ break; }
		}else{ 
			cout << "Error! Enter Valid Password: ";
			cin >> newPass;
		}
	}

	string secondTime = "";
	cout << "Enter New Password Again: ";
	cin >> secondTime;
	if(secondTime == newPass){
		password = newPass;
		cout << "Password Successfully Changed" << endl;
	}else{
		cout << "Error: Password Not Changed" << endl;
		secondMenu();
	}
}

void Donor::view(){

	cout << "Donor Info" << endl;
	cout << firstName << " " << lastName << ": age " << age << endl;
	cout << "User: " << userid << endl;
	cout <<"Password: " << password << endl;
	cout << streetNumber << " " << streetName << endl;
	cout << townName << ", NY " << zipCode << endl;

	cout.precision(2);
	cout << fixed << "Current Amount Donated: $" << totalAmt << endl;

}

void Donor::donate(float amt){
	
	totalAmt += amt;
}

void Donor::total(){

	cout.precision(2);
	cout << fixed << lastName << " $" << totalAmt << endl;

}

string Donor::getLastName(){ return lastName; }

string Donor::getFirstName(){ return firstName; }

string Donor::getUserID(){ return userid; }

string Donor::getPassword(){ return password; }

int Donor::getAge(){ return age; }

int Donor::getStreetNum(){ return streetNumber; }

string Donor::getStreetName(){ return streetName; }

string Donor::getTownName(){ return townName; }

string Donor::getZip(){ return zipCode; }

string Donor::getState(){ return sString; }

float Donor::getTotal(){ return totalAmt; }

int Donor::secondMenu(){

	cout << "Welcome " << firstName << " " << lastName << endl;

	while(true){

		cout << "Enter a Command" << endl;
		cout << "Choose from ['Manage' 'Password' 'View' 'Donate' 'Total' 'Logout']" << endl;
		string input = "";
		cout << ":";
		cin >> input;

		if(input == "Manage"){

			manage();

		}else if(input == "Password"){

			newPass();

		}else if(input == "View"){

			view();

		}else if(input == "Donate"){
			
			float amt = 0.0;
	
			while(true){
				cout << "Enter Donation Amount: ";
				if(!(cin >> amt)){
					cout << "Error: Enter Valid Amount" << endl;
				}else{ break; }
			}
			
			donate(amt);

		}else if(input == "Total"){

			total();
			
		}else if(input == "Logout"){
			
			return 0;
			
		}else{ cout << "Error! Enter Valid Command." << endl; }

	}

}

bool Donor::isString(const string &str){
	
	bool retVal = true;

	for(int i = 0; i < str.size(); i++){

		if(!isalpha(str[i])){

			retVal = false;

		}

	}

	return retVal;
	
}

bool Donor::isAlphaNumeric(const string &str){
	bool retVal = true;
	int num = 0;
	for(int i = 0; i < str.size(); i++){

		if(!isalnum(str[i])){ retVal = false; break; }
		if(isdigit(str[i])){ num++; }
	}

	if(num == 0){ retVal = false; }

	return retVal;

}

bool Donor::containsSpecialChar(const string &str){


	bool retVal = true;
	int num = 0;
	int special = 0;
	for(int i = 0; i < str.size(); i++){
		if(isdigit(str[i])) { num++; }
		if(!isalnum(str[i])) { special++; }
	}

	if(num == 0 || special == 0){ retVal = false; }

	return retVal;
}

bool Donor::isNum(const string &str){

	bool retVal = true;
	int num = 0;
	for(int i = 0; i < str.size(); i++){
		if(!isdigit(str[i])) { retVal = false; }
	}

	return retVal;

}

bool Donor::isValidString(const string &str){

	bool retVal = true;

	for(int i = 0; i < str.size(); i++){

		if(!isalpha(str[i]) && !isspace(str[i])){

			retVal = false;

		}

	}

	return retVal;

}

Donor::~Donor(){ }
