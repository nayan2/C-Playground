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

//typedef pair<string, string> attr;
//
//struct tag {
//	int id;
//	int parentIndex;
//	string identifier;
//	vector<attr> attributes;
//};
//
//vector<string> split(const string& str, const string& delim)
//{
//	vector<string> tokens;
//	size_t prev = 0, pos = 0;
//	do
//	{
//		pos = str.find(delim, prev);
//		if (pos == string::npos) pos = str.length();
//		string token = str.substr(prev, pos - prev);
//		if (!token.empty()) tokens.push_back(token);
//		prev = pos + delim.length();
//	} while (pos < str.length() && prev < str.length());
//	return tokens;
//}
//
//string find_attr(vector<tag> tags, vector<string>& queries, int index) {
//	string query = queries.at(index);
//	if (query.find('~') != string::npos) {
//		int pos = query.find('~');
//		string ftag = query.substr(0, pos);
//		string attr = query.substr(pos + 1, query.length());
//		auto ctags = find_if(tags.begin(), tags.end(), [&ftag](const tag& t) { return t.identifier == ftag; });
//		if (ctags == tags.end())
//			return "Not Found!";
//		else {
//			auto attrValue = find_if((*ctags).attributes.begin(), (*ctags).attributes.end(), [&attr](pair<string, string>& p) { return p.first == attr; });
//			if (attrValue == (*ctags).attributes.end()) return "Not Found!";
//			return (*attrValue).second;
//		}
//	}
//	else {
//		vector<tag> ctags;
//		auto utag = find_if(tags.begin(), tags.end(), [&query](const tag& t) { return t.identifier == query; });
//		auto ctag = find_if(tags.begin(), tags.end(), [utag](tag t) { return t.parentIndex == (*utag).id; });
//		while (ctag != tags.end())
//		{
//			ctags.push_back(*ctag);
//			ctag = find_if(next(ctag), tags.end(), [utag](tag t) { return t.parentIndex == (*utag).id; });
//		}
//		return find_attr(ctags, queries, ++index);
//	}
//}

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

int problem1() {
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
	return 0;
}
