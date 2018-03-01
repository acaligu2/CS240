#include "Credit.h"
#include <iostream> 
#include <stdlib.h>

Credit::Credit()
{
	creditName = "";
	totalNumber = 0;
	runningTotal = 0;
}

Credit::Credit(string n, string num)
{
	creditName = n;
	totalNumber = stoi(num);
}
string Credit::getName()
{ return creditName; }

int Credit::getNumber()
{ return totalNumber; }

int Credit::getRunningTotal()
{ return runningTotal; }

void Credit::setNumber(string n)
{ totalNumber = stoi(n); }

void Credit::setName(string s)
{ creditName = s; }

void Credit::increment(int x)
{ runningTotal += x; }
