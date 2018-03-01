#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Credit{

	private:

		string creditName;
		int totalNumber;
		int runningTotal;

	public:

		Credit();
		Credit(string n, string num);
		string getName();
		int getNumber();
		int getRunningTotal();
		void setName(string s);
		void setNumber(string n);
		void increment(int x);

};
