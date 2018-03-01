#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "FBLPostLL.h"
using namespace std;

class FBLUser{

	public:

		vector<FBLUser*> friends;
		string user;
		string pass;
		string firstName;
		string lastName;
		FBLPostLL * postList;
		FBLPostLL *myFeed;
		FBLPostLL *myWall;
		FBLUser();
		FBLUser(string user, string pass, string firstName, string lastName);
		void setUser(string u);
		void setPass(string p);
		void setFirst(string f);
		void setLast(string l);
		string getUser();
		string getPass();
		string getFirst();
		string getLast();
		void iterateFeed(string post, FBLPost * wallPost);
		void addFeed(string post, FBLPost * wallPost);
		FBLPost* addWall(string post);
		void readPost();
		void readWall();
		void readFeed();
		bool addFriend(FBLUser* newFriend);
		void myFriends();
		int thirdMenu();
		~FBLUser();

};
