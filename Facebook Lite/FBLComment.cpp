#include "FBLComment.h"

FBLComment::FBLComment(){
	
	comment = "";
	user = "";

}

FBLComment::FBLComment(string input, string username){

	comment = input;
	user = username;

}

string FBLComment::getComment(){ 
	return user + ": " + comment;
}

void FBLComment::setComment(string input){ comment = input; }
void FBLComment::setUser(string username){ user = username; }

FBLComment::~FBLComment(){}
