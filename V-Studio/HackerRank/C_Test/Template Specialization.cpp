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

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <typename T>
struct Traits {
private:
    static const string colors[3];
    static const string friuts[3];
    static const string UNK;
public:
    static string name(int index) {
        if (index > 2 || index < 0) return UNK;
        return typeid(T) == typeid(Fruit) ? friuts[index] : colors[index];
    }
};

template<typename T> const string Traits<T>::colors[3] = { "red","green","orange" };
template<typename T> const string Traits<T>::friuts[3] = { "apple","orange","pear" };
template<typename T> const string Traits<T>::UNK = "unknown";

int TS()
{
    int t = 0; std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}