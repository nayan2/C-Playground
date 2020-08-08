#include "rectangle_area.h"
#include <iostream>

using namespace std;

class Rectangle {
protected:
    int height;
    int width;

public:
    void display() {
        cout << this->width << " " << this->height << endl;
    }
};

class RectangleArea: public Rectangle {
public:
    void read_input() {
        cin >> this->width >> this->height;
    }

    void display() {
        cout << this->height * this->width << endl;
    }
};


int r_a()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}