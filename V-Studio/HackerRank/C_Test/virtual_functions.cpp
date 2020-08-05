#include "virtual_functions.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

class Person {
public:
    string name;
    int age;

public:
    virtual void getdata() {}
    virtual void putdata() {}
};

class Professor: public Person
{
private:
    int publications;
    int cur_id;
    static int count;

public:
    void getdata() {
        cin >> this->name >> this->age >> this->publications;
        Professor::count += 1;
        this->cur_id = Professor::count;
    }

    void putdata() {
        cout << this->name << " " << this->age << " " << this->publications << " " << Professor::cur_id << endl;
    }
};

class Student: public Person {
private:
    int marks[6];
    int cur_id{0};
    static int count;

public:
    void getdata() {
        cin >> this->name >> this->age;

        for (size_t i = 0; i < 6; i++)
        {
            cin >> this->marks[i];
        }
        Student::count += 1;
        this->cur_id = Student::count;
    }

    void putdata() {
        cout << this->name << " " << this->age << " " << accumulate(this->marks, this->marks + 6, 0) << " " << Student::cur_id << endl;
    }
};

int Student::count{ 0 };
int Professor::count{ 0 };

int v_f() {

    //int n, val;
    //cin >> n; //The number of objects that is going to be created.
    //Person* per[n];

    //for (int i = 0; i < n; i++) {

    //    cin >> val;
    //    if (val == 1) {
    //        // If val is 1 current object is of type Professor
    //        per[i] = new Professor;

    //    }
    //    else per[i] = new Student; // Else the current object is of type Student

    //    per[i]->getdata(); // Get the data from the user.

    //}

    //for (int i = 0; i < n; i++)
    //    per[i]->putdata(); // Print the required output for each object.

    return 0;

}
