#include "prettyprint.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <iomanip> 

using namespace std;

int p_p() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		//cout << showbase << internal << setfill('0') << std::hex << setw(4) << nouppercase << (int)A << endl;
		//cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;
		//cout << setprecision(9) << uppercase << noshowpos << scientific << C << endl;

		// LINE 1 
		cout << hex << left << showbase << nouppercase; // formatting
		cout << (long long)A << endl; // actual printed part

		// LINE 2
		cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
		cout << B << endl; // actual printed part

		// LINE 3
		cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
		cout << C << endl; // actual printed part
	}
	return 0;

}