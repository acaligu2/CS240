#include <iostream>
#include <stdlib.h>
using namespace std;

class Donor {

	private:

		string lastName;
		string firstName;
		string userid;
		string password;
		int age = 0;
		int streetNumber;
		string streetName;
		string townName;
		string zipCode;
		string state;
		float donationAmt = 0;
		float totalAmt = 0;
		string sString;
		enum states{ NY, PA, RI, NH, VT, MA, CT, ME };

	public:

		Donor();
		void add();
		void checkFirst(string fn);
		void checkLast(string ln);
		void checkUserID(string id);
		void checkPassword(string pass);
		void checkAge(string a);
		void checkStreetNumber(string sNum);
		void checkStreetName(string sn);
		void checkTownName(string t);
		void checkZip(string zip);
		void checkState(string s);
		void checkDonation(string s);
		void manage();
		void newPass();
		void view();
		void donate(float amt);
		void total();
		string getLastName();
		string getFirstName();
		string getUserID();
		string getPassword();
		int getAge();
		int getStreetNum();
		string getStreetName();
		string getTownName();
		string getZip();
		string getState();
		float getTotal();
		bool isString(const string &str);
		bool isAlphaNumeric(const string &str);
		bool containsSpecialChar(const string &str);
		bool isNum(const string &str);
		bool isValidString(const string &str);
		int secondMenu();
		~Donor();
};

