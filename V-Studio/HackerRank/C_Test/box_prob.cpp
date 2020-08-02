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

class Box
{
	friend ostream& operator<<(ostream& out, const Box& B);

private:
	int l;
	int b;
	int h;

public:
	Box(): l{ 0 }, b{ 0 }, h{0} {
	}

	Box(int l, int b, int h) : l{ l }, b{ b }, h{ h } {
	}

	Box(const Box& B) : l{ B.l }, b{ B.b }, h{ B.h } {
	}

	int getLength() {
		return this->l;
	}

	int getBreadth() {
		return this->b;
	}

	int getHeight() {
		return this->h;
	}

	long long CalculateVolume() {
		return (long)this->b * (long)this->h * (long)this->l;
	}


	bool operator<(const Box& B) const {
		if (this->l < B.l || (this->b < B.b && this->l == B.l) || (this->h < B.h && this->b == B.b && this->l == B.l))
			return true;
		return false;
	}
};

ostream& operator<<(ostream& out, const Box& B) {
	out << B.l << " " << B.b << " " << B.h;
	return out;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int b_p()
{
	check2();
	return 0;
}