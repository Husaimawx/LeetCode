#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
	int len = s.length();
	int maxlen = 0;
	int from, to;

	if (len == 0)
	{
		return s;
	}

	for (int i = 0; i < len; i++)
	{
		int tempLength = 1;
		int j;
		for (j = 1;; j++)
		{
			if (i - j >= 0 && i + j < len && s[i - j] == s[i + j])
				tempLength += 2;
			else
			{
				break;
			}
		}
		if (tempLength > maxlen)
		{
			maxlen = tempLength;
			from = i - j + 1;
			to = i + j - 1;
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		int tempLength = 0;
		int j;
		for (j = 0;; j++)
		{
			if (i - j >= 0 && i + j + 1 < len && s[i - j] == s[i + j + 1])
				tempLength += 2;
			else
			{
				break;
			}
		}
		if (tempLength > maxlen)
		{
			maxlen = tempLength;
			from = i - j + 1;
			to = i + j;
		}
	}

	return s.substr(from, to - from + 1);
}

int main()
{
	string a = longestPalindrome("a");
	string b = longestPalindrome("bba");
	string c = longestPalindrome("asdssd");
	string d = longestPalindrome("asdffdsssd");
	string e = longestPalindrome("bb");
	return 0;
};