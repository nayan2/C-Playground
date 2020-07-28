#include "Account.h"
#include <iostream>

void Account::Deposit() 
{
	cout << "amount deposited" << endl;
}

Account::Account() {
	cout << "Account created" << endl;
}

Account::~Account() {
	cout << "Account destroyed" << endl;
}