// bug version
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<2)
            return res;
        if (nums.size() == 2)
        {
            if (nums[0] <= nums[1])
                res.push_back(nums);
            return res;
        }

        int min = INT_MAX;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] < min)
                min = nums[i];
        }

        vector<int> min_num;
        int min_pos = 0;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] == min)
            {
                min_num.push_back(min);
                min_pos = i;
            }
        }
        vector<int> temp;
        for (int i = 0; i<nums.size(); i++)
        {
            if (i != min_pos)
                temp.push_back(nums[i]);
        }

        res = findSubsequences(temp);
        vector<int> sub(nums.begin() + min_pos + 1, nums.end());
        vector<vector<int>> res2 = findSubsequences(sub);
        for (int i = 0; i<res2.size(); i++)
        {
            res2[i].insert(res2[i].begin(), min_num.size(), min);
            res.push_back(res2[i]);
        }
        map<int, int> M;
        for (int i = min_pos + 1; i<nums.size(); i++)
        {
            if (M.count(nums[i]) == 0)
            {
                M[nums[i]] = 1;
                vector<int> plus_one = min_num;
                plus_one.push_back(nums[i]);
                res.push_back(plus_one);
            }
        }

        return res;
    }
};

// map solution
class Solution {
map<vector<int>, int> M;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<2)
            return res;
        if (nums.size() == 2)
        {
            if (nums[0] <= nums[1])
            {
                res.push_back(nums);
                M[nums] = 1;
            }
            return res;
        }
        
        int last = nums[nums.size()-1];
        vector<int> newnum = nums;
        newnum.pop_back();
        res = findSubsequences(newnum);
        int size = res.size();
        for(int i = 0;i<size;i++)
        {
            if(res[i][res[i].size()-1]>last)
                continue;
            vector<int> temp = res[i];
            temp.push_back(last);
            if(M.count(temp) == 0)   
            {
                M[temp] = 1;
                res.push_back(temp);
            }
        }
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i]>last)
                continue;
            vector<int> temp(1,nums[i]);
            temp.push_back(last);
            if(M.count(temp) == 0)   
            {
                M[temp] = 1;
                res.push_back(temp);
            }
        }    
        return res;
    }
};