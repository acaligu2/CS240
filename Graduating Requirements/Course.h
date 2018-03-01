#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Course{

	private:


		int credits;
		string offeringTime;
		vector<string> reqs;
		bool secondaryCheck;
		vector<char> secondary;
		

	public:

		Course(string credit, string offering);
		Course(string credit, string offering, string type);
		void setCredits(int c);
		void setOffering(string o);
		int getCredits();
		string getOfferingTime();
		void setReqs(string s);
		bool getCheck();
		vector<string> getReqs();
		vector<char> getSecondary();
		

};
