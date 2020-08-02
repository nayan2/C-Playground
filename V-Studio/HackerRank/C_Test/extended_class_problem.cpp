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
#include <numeric>

using namespace std;

class Student
{
private:
    int scores[5];
public:
    void input();
    int calculateTotalScore();
};

void Student::input() {
    for (size_t i = 0; i < 5; i++)
    {
        cin >> this->scores[i];
    }
}

int Student::calculateTotalScore() {
    return accumulate(this->scores, this->scores+(sizeof(this->scores)/sizeof(this->scores[0])), 0);
}

int x_c_p() {
    int n; // number of students
    cin >> n;
    Student* s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
