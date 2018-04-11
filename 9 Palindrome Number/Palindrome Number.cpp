#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	long long ruler = 1;
	for (; 10 * ruler<=x; ruler *= 10);
	while (1)
	{
		if (ruler < 10)
			return true;
		if (x / ruler != x % 10)
			return false;
		else
		{
			x = (x%ruler) / 10;
			ruler /= 100;
		}
	}
}

bool isPalindrome2(int x) {
	if (x<0 || (x != 0 && x % 10 == 0)) return false;
	int sum = 0;
	while (x>sum)
	{
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	return (x == sum) || (x == sum / 10);
}

int main()
{
	int a1 = isPalindrome(0);
	int a2 = isPalindrome(10);
	int a3 = isPalindrome(22);
	int a4 = isPalindrome(9);
	int a5 = isPalindrome(7227);
	int a6 = isPalindrome(919);
	int a7 = isPalindrome(99199);
	int a8 = isPalindrome(9001029);
	int a9 = isPalindrome(9001109);
	return 0;
};