#include "deque_stl.h"
#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> decs;
    bool shouldcheck = true;
    int max;

    for (size_t i = 0; i <= n; i++)
    {
        if (i >= k) {
            if (shouldcheck) {
                max = *max_element(decs.begin(), decs.end());
                cout << max << " ";
            }
            int result = decs.front();
            decs.pop_front();

            if (result != max && i == n)
                break;
            else if (result != max) {
                max = (arr[i] > max ? arr[i] : max);
                cout << max << " ";
                shouldcheck = false;
            }
            else
                shouldcheck = true;
        }
        decs.push_back(arr[i]);
    }
    cout << endl;
}

int deque_stl() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int *arr = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
            t--;
    }
    return 0;
}