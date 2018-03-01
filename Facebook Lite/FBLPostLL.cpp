#include <iostream>
#include <stdlib.h>
#include "FBLPostLL.h"
using namespace std;

FBLPostLL::FBLPostLL(){

	first = nullptr;

}

FBLPost* FBLPostLL::addPost(string post, string user, FBLPost * wallPost){

	FBLPostNode * newNode = new FBLPostNode(post, user, nullptr);
	if(newNode == nullptr){ return NULL; }
	
	newNode->next=first;
	first = newNode;
	return &(newNode->newPost);

}

bool FBLPostLL::addFeed(string post, string user, FBLPost * wallPost){

	FBLPostNode * newNode = new FBLPostNode(post, user, wallPost);
	if(newNode == nullptr){ return false; }
	
	newNode->next=first;
	first = newNode;
	return true;

}

int FBLPostLL::read(){

	if(first == nullptr){ cout << "	Nothing to read"; return 0; }

	for(FBLPostNode * pos = first; pos != nullptr; pos = pos->next){

		if(pos->next == nullptr){

			cout << endl;

			cout << "		" << pos->newPost.getPost() << endl;
			thirdMenu(pos->newPost);
			deletePost();
			break;
			

		}

	}

	return 0;

}

void FBLPostLL::wall(){

	for(FBLPostNode * pos = first; pos != nullptr; pos = pos->next){


		cout << "	Likes: " << pos->newPost.getLikes() << " " << 				pos->newPost.getPost() << endl;


	}

}

void FBLPostLL::feed(){

	for(FBLPostNode * pos = first; pos != nullptr; pos = pos->next){


		cout << "	" << pos->newPost.getPost() << endl;


	}

}

int FBLPostLL::thirdMenu(FBLPost &menuPost){
	
	FBLPost * wallPost = menuPost.getWallPost();

	cout << "		Third Level Menu" << endl;
	
	while(true){

		cout << "		Enter Third Level Option: ";
		string option;
		cin >> option;

		if(option == "LIKE"){ 

			wallPost->addLike(); 

		}
		else if(option == "COMMENT"){

			string comment = "";
			getline(cin, comment);
			wallPost->addComment(comment, menuPost.getUser());
			
			
		}
		else if(option == "READ_AZ"){ 
			
			wallPost->readCommentsAZ();

		}
		else if(option == "READ_ZA"){ 

			wallPost->readCommentsZA();

		}
		else if(option == "DONE"){ return 0; }
		else{ cout << "		Enter Valid Option" << endl; }


	}
			

}

void FBLPostLL::deletePost(){

	if (first->next == nullptr) {
    		delete first;
    		first = nullptr;
	}else {
    		FBLPostNode * temp1 = first;
    		FBLPostNode * temp2 = first->next;
    		while (temp2->next != nullptr) {
        		temp1 = temp2;
        		temp2 = temp2->next;
    		}
		temp1->next = nullptr;
		delete temp2;
	}
}

FBLPostLL::~FBLPostLL(){

	FBLPostNode *current = first;
	FBLPostNode *temp;
	while(current != nullptr){

		temp = current->next;
		delete current;
		current = temp;

	}

}
