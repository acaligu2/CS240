#include <iostream>
#include <stdlib.h>
#include "Donor.h"
using namespace std;

class DonorDatabase {

	private:

		int arrSize = 0;
		Donor * donorArray;
		int index = 0;

	public:

		DonorDatabase(int numDonors);
		void addElement(Donor newDonor);
		bool login(string userid);
		void mainMenu();
		void save();
		void load(string fileName);
		void report();
		~DonorDatabase();
};
