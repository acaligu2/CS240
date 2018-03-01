#include <iostream>
#include <stdlib.h>

using namespace std;

class FBLComment{

	public:
	
		string comment;
		string user;
		FBLComment();
		FBLComment(string input, string username);
		void setComment(string input);
		void setUser(string username);
		string getComment();
		~FBLComment();
		
};
