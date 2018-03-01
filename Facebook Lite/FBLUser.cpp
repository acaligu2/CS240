#include "FBLUser.h"

FBLUser::FBLUser(){

	user = "";
	pass = "";
	firstName = "";
	lastName = "";
	postList = new FBLPostLL();
	myFeed = new FBLPostLL();
	myWall = new FBLPostLL();

}

FBLUser::FBLUser(string u, string p, string fn, string ln){

	user = u;
	pass = p;
	firstName = fn;
	lastName = ln;
	postList = new FBLPostLL();
	myFeed = new FBLPostLL();
	myWall = new FBLPostLL();

}

void FBLUser::setUser(string u){ user = u; }
void FBLUser::setPass(string p){ pass = p; }
void FBLUser::setFirst(string f){ firstName = f; }
void FBLUser::setLast(string l){ lastName = l; }

string FBLUser::getUser(){ return user; }
string FBLUser::getPass(){ return pass; }
string FBLUser::getFirst(){ return firstName; }
string FBLUser::getLast(){ return lastName; }

void FBLUser::readPost(){

	myFeed->read();
	
}

void FBLUser::iterateFeed(string post, FBLPost * wallPost){ 

	for(int i = 0; i < friends.size(); i++){

		friends[i]->addFeed(post, wallPost);

	}

}

void FBLUser::addFeed(string post, FBLPost * wallPost){
 
	myFeed->addFeed(post, user, wallPost);

}

FBLPost* FBLUser::addWall(string post){ 

	FBLPost* wallPost = myWall->addPost(post, user, nullptr);
	return wallPost;

}
void FBLUser::readWall(){ myWall->wall(); }
void FBLUser::readFeed(){ myFeed->feed(); }


bool FBLUser::addFriend(FBLUser *newFriend){

	for(int i = 0; i < friends.size(); i++){

		if(friends[i]->getUser() == newFriend->getUser()){ return false; }

	}
	friends.push_back(newFriend);
	return true;

}

void FBLUser::myFriends(){

	if(friends.size() == 0){ cout << "	No Friends." << endl; }
	
	for(int i = 0; i < friends.size(); i++){
			
		cout << "	" <<friends[i]->getFirst() << " " << friends[i]->getLast() 			<< endl;

	}

}

FBLUser::~FBLUser(){

	delete postList;
	delete myFeed;
	delete myWall;

}
