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

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int number_of_workshops;
    Workshop* workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Workshop* newWorkshops = new Workshop[n];
    for (size_t i = 0; i < n; i++)
    {
        newWorkshops[i] = Workshop{ start_time[i], duration[i], start_time[i] + duration[i] };
    }
    return new Available_Workshops{ n, newWorkshops };
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int coursCount{ 1 };
    vector<pair<int, int>> start_and_totals;
    vector<pair<int, int>>::iterator vptr;

    for (size_t i = 0; i < ptr->number_of_workshops; i++)
    {
        start_and_totals.push_back(make_pair(ptr->workshops[i].start_time, ptr->workshops[i].end_time));
    }
    sort(start_and_totals.begin(), start_and_totals.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    vector<pair<int, int>>::iterator source = start_and_totals.begin();

    for(vptr = start_and_totals.begin() + 1; vptr < start_and_totals.end(); vptr++)
    {
        if (source->second <= (vptr)->first) {
            source = vptr;
            ++coursCount;
        }
    }
    delete ptr->workshops;
    delete ptr;
    return coursCount;
}

int workspace_challenge(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

