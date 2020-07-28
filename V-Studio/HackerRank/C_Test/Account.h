#pragma once
#include <string>
using namespace std;
class Account
{
	public:
		string number;
		int amount;
	public:
		void Deposit();
		Account();
		~Account();
};

