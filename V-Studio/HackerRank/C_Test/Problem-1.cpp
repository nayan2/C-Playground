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
typedef pair<string, string> attr;

string& purify(string& text) {
	text.erase(remove(text.begin(), text.end(), '\"'), text.end());
	text.erase(remove(text.begin(), text.end(), '</'), text.end());
	text.erase(remove(text.begin(), text.end(), '>'), text.end());
	text.erase(remove(text.begin(), text.end(), '<'), text.end());
	return text;
}

string get_identifier(stack<string> identifiers) {
	string line;
	while (!identifiers.empty())
	{
		if (line.length() <= 0 && identifiers.size() == 1)
			line = identifiers.top();
		else if (line.length() <= 0)
			line = "." + identifiers.top();
		else if (line.length() > 1 && identifiers.size() != 1)
			line = "." + identifiers.top() + line;
		else
			line = identifiers.top() + line;
		identifiers.pop();
	}
	return line;
}

int main() {
	int n, q, totalLines;
	cin >> n >> q;
	cin.ignore();
	string line, ans;
	vector<attr> attributes;
	stack<string> identifiers;
	for (size_t i = 0; i < n + q; i++)
	{
		getline(cin, line);
		if (i < n) {
			istringstream stream(line);
			string leftValue;
			bool foundOperator = false;
			while (stream >> line) {
				if (line.find('</') != string::npos) {
					identifiers.pop();
					continue;
				}
				else {
					if (line.find('<') != string::npos)
						identifiers.push(purify(line));
					else if (!foundOperator && line != "=")
						leftValue = line;
					else if (foundOperator && line != "=") {
						foundOperator = false;
						attributes.push_back(make_pair(get_identifier(identifiers) + "~" + leftValue, purify(line)));
					}
					else
						foundOperator = true;
				}
			}
		}
		else {
			auto itr = find_if(attributes.begin(), attributes.end(), [&line](attr& a) { return a.first == line; });
			if (itr != attributes.end())
				ans += (*itr).second + "\n";
			else
				ans += "Not Found!\n";
		}
	}

	cout << ans;
}
