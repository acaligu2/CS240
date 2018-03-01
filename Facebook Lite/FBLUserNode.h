#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"
using namespace std;

class FBLUserNode{


	public:
		
		FBLUser newData;
		FBLUserNode * next;

		FBLUserNode();
		FBLUserNode(string user, string pass, string firstName, string lastName);
		~FBLUserNode();

};
