#include <iostream>
#include <sstream>
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

template<typename Number>
auto Sum(const Number& number) {
    return number;
}

template<typename Number, typename ...Others>
auto Sum(const Number& number, Others ...rest) {
    return number + Sum(rest...);
}

template <typename Output>
void OutPutter(Output outputter) {
    cout << outputter << endl;
}

template <typename Output, typename ...Rest>
void OutPutter(const Output& outputter, Rest ...rest) {
    OutPutter(outputter);
    OutPutter(rest...);
}

template<typename init>
string concat_string(const init& first) {
    stringstream ss;
    ss << first;
    return ss.str();
}

template<typename init, typename ...Rest>
string concat_string(const init& first, Rest ...rest) {
    return concat_string(first) + concat_string(rest...);
}

template<typename init>
string to_string_imp(const init& str) {
    stringstream stream;
    stream << str;
    return stream.str();
}

template<typename ...Rest>
vector<string> to_string(Rest ...rest) {
    //vector<string> list;
    //list.push_back(to_string_imp(first));
    //const auto reminder = to_string(rest...);
    //list.insert(list.end(), reminder.begin(), reminder.end());
    //return list;

    return { "", "","","" };
}

int v_t()
{
    //Sum(1, 2, 3, 4, 5);
    //OutPutter(1,2,3,4,5);
    //cout << concat_string("x", "y", "z") << endl;

    const auto result = to_string(1, 2, 3, "x", "y");
    return 0;
}
