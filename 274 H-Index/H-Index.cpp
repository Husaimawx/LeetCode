class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        int size = citations.size();
        sort(citations.begin(),citations.end());
        vector<int> ans;
        for(int i = 0;i < size;i++)
        {
            ans.push_back(size-i);
        }
        for(int i = 0;i<size;i++)
        {
            if(ans[i] <= citations[i])
                return ans[i];
        }
        return 0;
    }
};