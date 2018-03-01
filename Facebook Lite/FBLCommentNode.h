#include <iostream>
#include <stdlib.h>
#include "FBLComment.h"
using namespace std;

class FBLCommentNode{


	public:
		
		FBLComment newComment;
		FBLCommentNode * next;
		FBLCommentNode * prev;

		FBLCommentNode();
		FBLCommentNode(string input, string user);
		~FBLCommentNode();

};
