#include <iostream>
#include <stdlib.h>
#include "FBLPost.h"
using namespace std;

class FBLPostNode{


	public:
		
		FBLPost newPost;
		FBLPostNode * next;

		FBLPostNode();
		FBLPostNode(string input, string user, FBLPost * wallPost);
		~FBLPostNode();

};
