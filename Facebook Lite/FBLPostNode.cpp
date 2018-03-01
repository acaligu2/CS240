#include "FBLPostNode.h"

FBLPostNode::FBLPostNode(){

	next = nullptr;

}

FBLPostNode::FBLPostNode(string input, string user, FBLPost * wallPost){

	newPost.setPost(input);
	newPost.setUser(user);
	newPost.setWallPost(wallPost);
	next = nullptr;

}

FBLPostNode::~FBLPostNode(){ }
