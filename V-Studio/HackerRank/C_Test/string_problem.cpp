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

using namespace std;

int s_p() {
	string line[2];
	char temp;
	for (size_t i = 0; i < 2; i++)
	{
		cin >> line[i];
	}

	cout << line[0].length() << " " << line[1].length() << endl;
	cout << line[0] + line[1] << endl;
	temp = line[0][0];
	line[0][0] = line[1][0];
	line[1][0] = temp;
	cout << line[0] << " " << line[1] << endl;
	return 0;
}