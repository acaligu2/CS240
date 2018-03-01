#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "DonorDatabase.h"

using namespace std;
void mainMenu(int num);

int main(int argc, char *argv[]){
	
	while(true){
		if(argc < 2 || argc > 3) { cout << "Enter Proper Arguments." << endl; return 0; }
		else{ break; }
	}

	int num = stoi(argv[1]);	

	while(true){

		if(num <1 || num > 1000){

			cout << "Error: Enter Valid MaxDonor Amount: ";
			cin >> num;
		}else{ break; }

	}
	
	DonorDatabase *donorData = new DonorDatabase(num);

	if(argc == 3){ 
		string fileName = argv[2];
		donorData->load(fileName); 
	}

	donorData->mainMenu();
	
	return 0;

}
