#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "FBLUserLL.h"
using namespace std;

int main(int argc, char *argv[]){

	FBLUserLL * linkedList; 
	linkedList = new FBLUserLL();

	while(true){		
		string option = "";
		string user = "";
		string pass = "";
		string firstName = "";
		string lastName = "";

		cout << endl;


		cout << "Top Level Menu" << endl;
		cout << "Enter Option: ";
		
		cin >> option;

		if(option == "CREATE"){
			
			cin >> user >> pass >> firstName >> lastName;
			linkedList->addUser(user, pass, firstName, lastName);

		}else if(option == "LOGIN"){ 

			cin >> user >> pass;
			linkedList->login(user, pass);

		}else if(option == "USERS"){

			linkedList->users();

		}else if(option == "SORTUSERS"){

			linkedList->sort();
 
		}else if(option == "QUIT") { 

			break;

 		}else{ cout << "Enter Valid Input" << endl; }

	}

	delete linkedList;
	return 0;

}
