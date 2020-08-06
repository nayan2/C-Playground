#include "vector_sort.h"
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

int v_s() {
    int N, ind;
    cin >> N;
    vector<int> list;
    for (size_t i = 0; i < N; i++)
    {
        cin >> ind;
        list.push_back(ind);
    }
    sort(list.begin(), list.end());
    for (size_t i = 0; i < N; i++)
    {
        cout << list.at(i) << " ";
    }
    return 0;
}
