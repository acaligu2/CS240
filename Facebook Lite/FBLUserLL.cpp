#include <iostream>
#include <stdlib.h>
#include "FBLUserLL.h"
using namespace std;

FBLUserLL::FBLUserLL(){

	first = nullptr;
	last = nullptr;
	logins = 0;
}

bool FBLUserLL::addUser(string user, string pass, string firstName, string lastName){

	if(first){	
		for(FBLUserNode *pos = first; pos != nullptr; pos=pos->next){

			if(pos->newData.getUser() == user){

				cout << "Error: Username Taken!" << endl;
				return false;

			}	

		}
	}
	FBLUserNode * newNode = new FBLUserNode(user, pass, firstName, lastName);;
	if(newNode == nullptr){ return false; }
	newNode->next = first;
	first = newNode;
	return true;
 	
}

int FBLUserLL::users(){

	if(first == nullptr){ cout << "No Users" << endl; return 0; }

	for(FBLUserNode *pos = first; pos!= nullptr; pos=pos->next){

		string u = pos->newData.getUser();
		string f = pos->newData.getFirst();
		string l = pos->newData.getLast();

		cout << l << ", " << f << " <" << u << ">" << endl;

	}
	
	return 0;

}

void FBLUserLL::sort(){

	FBLUserNode* current = first;
	int amtOfNodes = 0;
	while(current != nullptr){
		amtOfNodes++;
		current = current->next;
	}
	for(int i = amtOfNodes; i > 1; i-- ){

		FBLUserNode *temp;
		FBLUserNode * swap1;
		swap1 = first;
		for(int j = 0; j < amtOfNodes-1; j++){

			if(swap1->newData.getLast() > swap1->next->newData.getLast()){

				FBLUserNode *swap2 = swap1->next;
				swap1->next = swap2->next;
				swap2->next = swap1;

				if(swap1 == first){

				    first = swap2;
				    swap1 = swap2;

				}else{

				    swap1 = swap2;
				    temp->next = swap2;

				}

			}

			temp = swap1;
			swap1 = swap1->next;			
	
		}

	}

}

bool FBLUserLL::login(string user, string pass){
	
	for(FBLUserNode *pos = first; pos != nullptr; pos=pos->next){

		if(pos->newData.getUser() == user){

			if(pos->newData.getPass() == pass){
			
				secondMenu(pos->newData);
				return true;

			}else{ cout << "Wrong Password" << endl; return false; }

		}

	}

	cout << "Username not in System." << endl;

	return false;
	

}

bool FBLUserLL::secondMenu(FBLUser &current){

	logins++;
	cout << endl;

	cout << "	Welcome " << current.getFirst() << " " << current.getLast() << endl;
	cout << "	Second Level Menu" << endl;
	
	while(true){

		string post;
		cout << "	Enter Second Level Option: ";
		string option;
		cin >> option;
			
		if(option == "POST"){ 

			getline(cin, post);
			FBLPost* wallPost = current.addWall(post);
			current.iterateFeed(post, wallPost);
		
		}
		else if(option == "READ"){ 

			current.readPost();
			cout << endl;
		
		}
		else if(option == "FRIEND"){

			string username = "";
			cin >> username;
			FBLUser* name = findFriend(username);
			if(name){
				bool res = current.addFriend(name);
				if(res){ 

					FBLUser* tempCurr = &current;
					(*name).addFriend(tempCurr);

				}
				else{ cout << "	Already Friends" << endl; }
			}

		}
		else if(option == "MYFRIENDS"){
	
			current.myFriends();		

		}
		else if(option == "MYFEED"){

			current.readFeed();

		}
		else if(option == "MYWALL"){

			current.readWall();

		}
		else if(option == "LOGOUT"){ return 0; }

		else{ cout << "	Enter Valid Input" << endl; }
	}

}

FBLUser* FBLUserLL::findFriend(string username){

	for(FBLUserNode *pos = first; pos != nullptr; pos=pos->next){

		if(username == pos->newData.getUser()){

			FBLUser* name = &pos->newData;
			return name;

		}

	}

	cout << "	User not in System" << endl;
	return nullptr;
}

FBLUserLL::~FBLUserLL(){

	FBLUserNode *current = first;
	FBLUserNode *temp;
	while(current != nullptr){

		temp = current->next;
		delete current;
		current = temp;

	}

}
