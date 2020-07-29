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
#include<iomanip>

using namespace std;

int b_d_i_p() {
	int a;
	long b;
	char c;
	float d;
	double e;

	cin >> a >> b >> c >> d >> e;

	cout << a << '\n' << b << '\n' << c << '\n' << fixed << setprecision(3) << d << '\n' << fixed << setprecision(9) << e << '\n';
	return 0;
}