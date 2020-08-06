#include "cpp_lower_bound.h"
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

int ccp_l_b() {
    int length, N;
    cin >> length;
    vector<int> vec;

    while (length--)
    {
        cin >> N;
        vec.push_back(N);
    }

    cin >> length;
    while (length--)
    {
        cin >> N;
        auto result = lower_bound(vec.begin(), vec.end(), N);
        cout << (*result == N ? "Yes " : "No ") << (result - vec.begin()) + 1 << endl;
    }
    return 0;
}
