class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        if(nums.size() == 0)
            return res;
        countSmallerAux(nums, res, 0, nums.size()-1);
        return res;
    }
    
    vector<int> countSmallerAux(vector<int>& nums, vector<int>& res, int from, int to) {
        if (from == to) {
            vector<int> ret(1, from);
            return ret;
        }
        if (from + 1 == to) {
            vector<int> ret(2, from);
            if (nums[from] <= nums[to])
                ret[1] = to;
            else {
                ret[0] = to;
                res[from] = 1;
            }
            return ret;
        }
        int mid = (from + to) / 2;
        vector<int> res1 = countSmallerAux(nums, res, from, mid);
        vector<int> res2 = countSmallerAux(nums, res, mid + 1, to);
        vector<int> ret(to - from + 1, 0);
        int f1 = from;
        int f2 = mid + 1;
        for (int i = 0; i <= to - from; i++) {
            if (f1 == mid + 1) {
                ret[i] = res2[f2 - mid - 1];
                f2++;
            }
            else if (f2 == to + 1) {
                ret[i] = res1[f1 - from];
                res[res1[f1-from]] += (to - mid);
                f1++;
            }
            else {
                if (nums[res1[f1-from]] <= nums[res2[f2-mid-1]]) {
                    ret[i] = res1[f1 - from];
                    res[res1[f1-from]] += (f2 - mid - 1);
                    f1++;
                }
                else {
                    ret[i] = res2[f2 - mid - 1];
                    f2++;
                }
            }
        }
        return ret;
    }
};