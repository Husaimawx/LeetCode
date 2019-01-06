class Solution {
public:
vector<int> merge(vector<int>& nums1, vector<int>& nums2, vector<int> res1, vector<int> res2) {
	vector<int> res(res1.size() + res2.size(), 0);
	int f1 = 0;
	int f2 = 0;
	for (int i = 0; i<res1.size() + res2.size(); i++) {
		if (f1 == res1.size()) {
			res[i] = nums2[res2[f2]];
			f2++;
		}
		else if (f2 == res2.size()) {
			res[i] = nums1[res1[f1]];
			f1++;
		}
		else {
			if (nums1[res1[f1]] > nums2[res2[f2]]) {
				res[i] = nums1[res1[f1]];
				f1++;
			}
			else if(nums1[res1[f1]] < nums2[res2[f2]]){
				res[i] = nums2[res2[f2]];
				f2++;
			}
			else {
				for (int s = 1;; s++) {
					if (f1 + s >= res1.size()) {
						res[i] = nums2[res2[f2]];
						f2++;
						break;
					}
					if (f2 + s >= res2.size()) {
						res[i] = nums1[res1[f1]];
						f1++;
						break;
					}
					if (nums1[res1[f1 + s]] < nums2[res2[f2 + s]]) {
						res[i] = nums2[res2[f2]];
						f2++;
						break;
					}
					if (nums1[res1[f1 + s]] > nums2[res2[f2 + s]]) {
						res[i] = nums1[res1[f1]];
						f1++;
						break;
					}
					if (nums1[res1[f1 + s]] < nums1[res1[f1]]) {
						res[i] = nums1[res1[f1]];
						f1++;
						break;
					}
				}
			}
		}
	}
	return res;
}

bool compare(vector<int>& nums1, vector<int>& nums2) {
	for (int i = 0; i<nums1.size(); i++) {
		if (nums1[i] > nums2[i])
			return true;
		else if (nums1[i] < nums2[i])
			return false;
	}
	return false;
}

void getMaxPre(vector<int>& nums1, int k, vector<vector<int>>& res) {
	if (k > nums1.size())
		k = nums1.size();
	vector<int> t;
	res.push_back(t);
	for (int i = 1; i <= k; i++) {
		if (i == 1) {
			vector<int> temp;
			int pos = 0;
			for (int j = 0; j<nums1.size(); j++) {
				if (nums1[j] > nums1[pos])
					pos = j;
			}
			temp.push_back(pos);
			res.push_back(temp);
		}
		else {
			vector<int> temp = res[res.size() - 1];
			if (temp[temp.size() - 1] != nums1.size() - 1) {
				int pos = temp[temp.size() - 1] + 1;
				for (int j = temp[temp.size() - 1] + 1; j<nums1.size(); j++) {
					if (nums1[j] > nums1[pos])
						pos = j;
				}
				temp.push_back(pos);
				res.push_back(temp);
			}
			else {
				int j;
				for (j = temp.size() - 1; j >= 0; j--) {
					if (temp[j] != nums1.size() - temp.size() + j)
						break;
				}
				int pos;
				if (j >= 0)
					pos = temp[j] + 1;
				else
					pos = 0;
				for (int k = pos; k<temp[j + 1]; k++) {
					if (nums1[k] > nums1[pos])
						pos = k;
				}
				temp.insert(temp.begin() + 1 + j, pos);
				res.push_back(temp);
			}
		}
	}
	return;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<int> res;
	if (k == 0)
		return res;
	if (nums1.size() + nums2.size() < k)
		return res;

	vector<vector<int>> res1;
	vector<vector<int>> res2;
	getMaxPre(nums1, k, res1);
	getMaxPre(nums2, k, res2);
	for (int i = 0; i <= k; i++) {
		if (i > nums1.size() || (k - i) > nums2.size())
			continue;
		vector<int> temp = merge(nums1, nums2, res1[i], res2[k - i]);
		if (res.size() == 0 || compare(temp, res))
			res = temp;
	}
	return res;
}
};