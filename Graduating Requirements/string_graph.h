#include <iostream>
#include <vector>

using namespace std;

class coursenode{
public:
	string coursename;
	coursenode *next;
};

class courselist{
public:	
	string srcname;
	coursenode *head;
};

//v: the number of all courses
class coursegraph{
private:
	int v;
	courselist* array;
	vector<string> coursename;
public:
	coursegraph(int v, vector<string> coursename);
	coursenode* newnode(string coursename);
	void addEdge(string src,string dest);
	void print();
	int getindex(string name);
	bool isrequire(string srcname,string desname);
	string getrequire(string coursename);
	~coursegraph();
};

	
