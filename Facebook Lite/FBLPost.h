#include <iostream>
#include <stdlib.h>
#include "FBLCommentLL.h"

using namespace std;

class FBLPost{

	public:
	
		string post;
		string username;
		FBLPost * wallPost;
		FBLCommentLL * comments;
		int likes;
		FBLPost();
		FBLPost(string input, string user, FBLPost * wallPost);
		string getPost();
		string getUser();
		FBLPost* getWallPost();
		void setPost(string input);
		void setUser(string user);
		void setWallPost(FBLPost * wall);
		void addComment(string comment, string user);
		void readCommentsAZ();
		void readCommentsZA();
		void addLike();
		int getLikes();
		~FBLPost();
		
};
