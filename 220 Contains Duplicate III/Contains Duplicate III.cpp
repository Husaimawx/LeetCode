class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2)
            return false;
        if(t < 0)
            return false;
        if(k > nums.size()-1)
            k = nums.size()-1;
        multiset<int> m;
        std::multiset<int>::iterator it;
        for(int i = 0;i<nums.size();i++) {
            it = m.insert(nums[i]);
            if(it != m.begin()) {
                it--;
                if(*it + t >= nums[i])
                    return true;
                it++;
            }
            it++;
            if(it != m.end()) {
                if(*it <= nums[i]+t)
                    return true;
            }
            if(m.size() > k)
                m.erase(m.find(nums[i-k]));
        }
        return false;
    }
};