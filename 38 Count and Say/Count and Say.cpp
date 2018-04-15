#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string convert(string input)
{
	int len = input.length();
	string ans = "";
	int last = 0;
	for (int i = 1; i<len; i++)
	{
		if (input[i] != input[i - 1])
		{
			ans += to_string(i - last) + input[i - 1];
			last = i;
		}
	}
	ans += to_string(len - last) + input[len - 1];
	return ans;
}

string countAndSay(int n) {
	if (n == 1)
		return "1";
	if (n == 2)
		return "11";
	string ans = "11";
	for (int i = 2; i<n; i++)
	{
		ans = convert(ans);
	}
	return ans;
}

int main()
{
	string a = countAndSay(1);
	string b = countAndSay(2);
	string c = countAndSay(3);
	string d = countAndSay(4);
	string e = countAndSay(5);
	string f = countAndSay(6);
	string g = countAndSay(30);
	return 0;
};