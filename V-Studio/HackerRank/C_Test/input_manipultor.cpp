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

vector<int> parseInts(string str) {
    vector<int> inputs;
    int input;
    replace(str.begin(), str.end(), ',', ' ');
    istringstream stream(str);
    while (stream >> input)
    {
        inputs.push_back(input);
    }
    return inputs;
}

int i_m() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}