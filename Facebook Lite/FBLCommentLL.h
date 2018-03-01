#include <iostream>
#include <stdlib.h>
#include "FBLCommentNode.h"
using namespace std;

class FBLCommentLL{

	public:
	
		FBLCommentNode * first;
		FBLCommentNode * last;
		FBLCommentLL();
		bool addComment(string input, string user);
		void readAZ();
		void readZA();
		~FBLCommentLL();
		

};
