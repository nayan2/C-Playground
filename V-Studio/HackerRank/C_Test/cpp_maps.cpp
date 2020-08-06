#include "cpp_maps.h"
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
#include <map>

using namespace std;

int cpp_maps() {
    int length, N; string name;
    cin >> length;
    map<string, int> maps;

    while (length--)
    {
        cin >> N;
        switch (N)
        {
        case 1: {
            cin >> name >> N;
            auto result = maps.find(name);
            if (result != maps.end()) 
                result->second += N;
            else
                maps.emplace(name, N);
            break;
        }
        case 2:
            cin >> name;
            maps.erase(name);
            break;
        case 3: {
            cin >> name;
            auto result = maps.find(name);
            cout << (result == maps.end() ? 0 : result->second) << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}