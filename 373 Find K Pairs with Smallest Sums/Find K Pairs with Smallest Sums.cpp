class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int,int>> res;
        if(nums1.empty() || nums2.empty() || k <=0 )
            return res;
        
        auto cmp = [](const pair<int,int> a, const pair<int,int> b)
        {
            return (a.first+a.second > b.first+b.second);
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        
        for(auto n : nums1)
            for(auto m : nums2)
            {
                minHeap.emplace(pair<int,int>(n,m));
                if()
            }
        
        if(k > nums1.size()*nums2.size())
            k = nums1.size()*nums2.size();
        for(int i = 0;i<k;i++)
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};