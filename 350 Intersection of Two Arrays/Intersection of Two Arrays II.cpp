class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        if(nums1.size() == 0 || nums2.size() == 0)
        {
            return ans;
        }
        
        map<int,int> m1,m2;
        for(auto item : nums1)
        {
            if(m1.find(item) != m1.end())
            {
                m1[item] += 1;
            }
            else
            {
                m1.insert(pair<int,int>(item,1));
            }
        }
        
        for(auto item : nums2)
        {
            if(m2.find(item) != m2.end())
            {
                m2[item] += 1;
            }
            else
            {
                m2.insert(pair<int,int>(item,1));
            }
        }
        
        int min;
        for(auto iter = m1.begin(); iter != m1.end(); iter++)
        {
            if(m2.find(iter->first) != m2.end())
            {
                min = (m2[iter->first] < m1[iter->first]) ? m2[iter->first]: m1[iter->first];
                for(int i = 0;i<min;i++)
                {
                    ans.push_back(iter->first);
                }
            }
        }  
        
        return ans;     
    }
};