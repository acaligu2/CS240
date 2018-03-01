#include "FBLUserNode.h"

FBLUserNode::FBLUserNode(){

	next = nullptr;

}

FBLUserNode::FBLUserNode(string user, string pass, string firstName, string lastName){

	newData.setUser(user);
	newData.setPass(pass);
	newData.setFirst(firstName);
	newData.setLast(lastName);
	next = nullptr;

}

FBLUserNode::~FBLUserNode(){ }
