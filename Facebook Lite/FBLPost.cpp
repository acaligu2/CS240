#include "FBLPost.h"

FBLPost::FBLPost(){
	
	post = "";
	username = "";
	wallPost = nullptr;
	likes = 0;
	comments = new FBLCommentLL();

}

FBLPost::FBLPost(string input, string user, FBLPost * wall){

	post = input;
	username = user;
	wallPost = wall;

}

string FBLPost::getPost(){ return post; }
string FBLPost::getUser(){ return username; }
FBLPost * FBLPost::getWallPost(){ return wallPost; }
void FBLPost::setPost(string input){ post = input; }
void FBLPost::setUser(string user){ username = user; }
void FBLPost::setWallPost(FBLPost * wall){ wallPost = wall; }

void FBLPost::addLike(){ likes++; }
void FBLPost::addComment(string comment, string user){

	comments->addComment(comment, user);

}

void FBLPost::readCommentsAZ(){

	comments->readAZ();

}

void FBLPost::readCommentsZA(){

	comments->readZA();

}

int FBLPost::getLikes(){ return likes; }

FBLPost::~FBLPost(){

	delete comments;

}
