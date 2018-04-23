// other people's code
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

// my code
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> lastres;
        int len = nums.size();
        if(len == 0 || len == 1)
        {
            res.push_back(nums);
            return res;
        }
        
        vector<int> copy;
        set<int> hset;
        for(int i = 0;i< len;i++)
        {
            int chooseNum = nums[i];
            if(hset.find(chooseNum) != hset.end())
                continue;
            else
            {
                hset.insert(nums[i]);
                copy = nums;
                copy[i] = copy[len-1];
                copy.pop_back();
                lastres = permuteUnique(copy);
                for(auto iter = lastres.begin();iter<lastres.end();iter++)
                {
                    (*iter).push_back(chooseNum);
                    res.push_back((*iter));
                }   
            }
        }
        return res;
    } 
};