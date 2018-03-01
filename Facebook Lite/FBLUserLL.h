#include <iostream>
#include <stdlib.h>
#include "FBLUserNode.h"
using namespace std;

class FBLUserLL{

	public:
	
		int logins;
		FBLUserNode * first;
		FBLUserNode * last;
		FBLUserLL();
		bool addUser(string user, string pass, string firstName, string lastName);
		int users();
		void sort();
		bool login(string user, string pass);
		bool secondMenu(FBLUser &current);
		FBLUser* findFriend(string username);
		~FBLUserLL();
		

};
