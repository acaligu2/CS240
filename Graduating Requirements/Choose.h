#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Choose
{
	private:
		int numNeeded;
		vector<string> course;
	public:
		int getNum();
		void setNum(string num);
		void addToVec(string c);
		void printVec();
		bool check(vector<string> classes);
};
