#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double largestTriangleArea(vector<vector<int>>& p) {
	double res = 0;
	for (auto &i : p)
		for (auto &j : p)
			for (auto &k : p)
				res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1] - j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
	return res;
}

int main()
{
	vector<vector<int>> p;
	vector<int> a, b, c;
	a.push_back(0);
	a.push_back(0);
	b.push_back(0);
	b.push_back(1);
	c.push_back(2);
	c.push_back(0);
	p.push_back(a);
	p.push_back(b);
	p.push_back(c);

	cout << largestTriangleArea(p);
	return 0;
};