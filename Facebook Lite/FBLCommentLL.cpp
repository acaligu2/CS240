#include <iostream>
#include <stdlib.h>
#include "FBLCommentLL.h"
using namespace std;

FBLCommentLL::FBLCommentLL(){

	first = nullptr;
	last = nullptr;

}

bool FBLCommentLL::addComment(string comment, string user){

	FBLCommentNode * newNode = new FBLCommentNode(comment, user);
	if(first == nullptr){

		first = newNode;
		last = first;
		return true;

	}else{

		newNode->prev = last;
		last->next = newNode;
		last = newNode;
		return true;

	}
	
}

void FBLCommentLL::readAZ(){

	for(FBLCommentNode * pos = first; pos != nullptr; pos = pos->next){

		cout << "		" << pos->newComment.getComment() << endl;

	}

}

void FBLCommentLL::readZA(){

	for(FBLCommentNode * pos = last; pos != nullptr; pos = pos->prev){


		cout << "		" << pos->newComment.getComment() << endl;

	}

}

FBLCommentLL::~FBLCommentLL(){

	FBLCommentNode *current = first;
	FBLCommentNode *temp;
	while(current != nullptr){

		temp = current->next;
		delete current;
		current = temp;

	}

}
