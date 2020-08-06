#include "cpp_sets.h"
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

int cpp_sets() {
    int length, N; cin >> length;
	set<int> sets;

	while (length--)
	{
		cin >> N;
		switch (N)
		{
			case 1:
				cin >> N;
				sets.insert(N);
				break;
			case 2: {
				cin >> N;
				auto result = sets.find(N);
				if(result != sets.end()) sets.erase(result);
				break;
			}
			case 3:
				cin >> N;
				cout << (sets.find(N) != sets.end() ? "Yes" : "No") << endl;
				break;
			default:
				break;
		}
	}
    return 0;
}