#include "FBLCommentNode.h"

FBLCommentNode::FBLCommentNode(){

	next = nullptr;
	prev = nullptr;

}

FBLCommentNode::FBLCommentNode(string input, string user){

	newComment.setComment(input);
	newComment.setUser(user);
	next = nullptr;
	prev = nullptr;

}

FBLCommentNode::~FBLCommentNode(){ }
