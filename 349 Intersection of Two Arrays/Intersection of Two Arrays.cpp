class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0)
        {
            vector<int> ans;
            return ans;
        }
        set<int> s1(nums1.begin(),nums1.end()), res;
        for(auto item : nums2)
        {
            if(s1.count(item))
            {
                res.insert(item);
            }
        }
        vector<int> ans(res.begin(),res.end());
        return ans;
    }
};