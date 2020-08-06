#include "vector_erase.h"
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

int v_e() {
    int N, X; string line;
    vector<int> vec;
    for (size_t i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            cin >> N;
            cin.ignore();
            break;
        case 1:
            for (size_t i = 0; i < N; i++)
            {
                cin >> X;
                vec.push_back(X);
            }
            break;
        case 2:
            cin >> N;
            cin.ignore();
            vec.erase(vec.begin() + (N - 1));
            break;
        case 3:
            cin >> N >> X;
            vec.erase(vec.begin() + (N - 1), vec.begin() + (X - 1));
            break;
        default:
            break;
        }
    }

    cout << vec.size() << endl;
    for (auto x: vec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}