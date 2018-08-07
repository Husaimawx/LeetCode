class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> Num;
        if(nums.size() == 0)
            return false;
        if(k == 0)
            return false;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(Num.find(nums[i]) != Num.end())
                return true;
            Num.insert(nums[i]);
            if(Num.size() > k)
                Num.erase(nums[i-k]);
        }
        return false;
    }
};