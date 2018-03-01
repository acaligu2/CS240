#include <iostream>
#include <stdlib.h>
#include "FBLPostNode.h"
using namespace std;

class FBLPostLL{

	public:
	
		FBLPostNode * first;
		FBLPostLL();
		FBLPost* addPost(string post, string user, FBLPost * wallPost);
		bool addFeed(string post, string user, FBLPost * wallPost);
		int read();
		void deletePost();
		void wall();
		void feed();
		int thirdMenu(FBLPost &post); 
		~FBLPostLL();
		

};
