#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double checkRightPlace(vector<int>& nums1, vector<int>& nums2, int half, int isodd, int place)
{
	int place2 = half - place;
	if (nums1.size() != place && place2 != 0)
	{
		if (nums2[place2 - 1]>nums1[place])
			return 1.2;
	}
	if (nums2.size() != place2 && place != 0)
	{
		if (nums1[place - 1]>nums2[place2])
			return 1.8;
	}
	if (isodd == 1)
	{
		if (nums1.size() == place)
			return nums2[place2];
		if (nums2.size() == place2)
			return nums1[place];
		else
			return min(nums2[place2], nums1[place]);
	}
	int leftnum, rightnum;
	if (nums1.size() == place)
		rightnum = nums2[place2];
	else if (nums2.size() == place2)
		rightnum = nums1[place];
	else
		rightnum = min(nums2[place2], nums1[place]);
	if (place == 0)
		leftnum = nums2[place2 - 1];
	else if (place2 == 0)
		leftnum = nums1[place - 1];
	else
		leftnum = max(nums2[place2 - 1], nums1[place - 1]);
	return (double)(leftnum + rightnum) / 2;
}

double findMedianSortedArrays_swap(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size();
	int len2 = nums2.size();
	int half = (len1 + len2) / 2;
	int isodd = (len1 + len2) % 2;
	int from = 0;
	int to = len1;
	int mid;
	while (from <= to)
	{
		mid = (from + to) / 2;
		double temp = checkRightPlace(nums1, nums2, half, isodd, mid);

		if (temp == 1.2)
		{
			from = mid + 1;
		}
		else if (temp == 1.8)
		{
			to = mid - 1;
		}
		else
		{
			return temp;
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size();
	int len2 = nums2.size();
	if (len1 == 0)
	{
		if (len2 == 0)
			return 0;
		if (len2 % 2 == 1)
		{
			return nums2[len2 / 2];
		}
		else
		{
			return (double)(nums2[len2 / 2] + nums2[len2 / 2 - 1]) / 2;
		}
	}
	if (len2 == 0)
	{
		if (len1 % 2 == 1)
		{
			return nums1[len1 / 2];
		}
		else
		{
			return (double)(nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2;
		}
	}
	if (len1 > len2)
	{
		return findMedianSortedArrays_swap(nums2, nums1);
	}
	else
	{
		return findMedianSortedArrays_swap(nums1, nums2);
	}
}

int main()
{
	vector<int> a;
	//a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	//a.push_back(4);
	//a.push_back(5);
	//a.push_back(6);
	vector<int> b;
	//b.push_back(2);
	//b.push_back(3);
	//b.push_back(7);
	//b.push_back(8);
	//b.push_back(5);
	double ans = findMedianSortedArrays(a,b);
	return 0;
};