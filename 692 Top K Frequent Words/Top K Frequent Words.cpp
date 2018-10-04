class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> M;
        for(int i = 0;i<words.size();i++)
        {
            if(M.count(words[i]) == 0)
            {
                M[words[i]] = 1;
            }
            else
            {
                M[words[i]] += 1;
            }
        }
        vector<vector<string>> bucket(words.size(),vector<string>());
        for(auto i=M.begin();i!=M.end();i++)
        {
            bucket[i->second].push_back(i->first);
        }
        
        for(int i = bucket.size()-1;i>=0;i--)
        {
            if(bucket[i].size() > 0)
            {
                sort(bucket[i].begin(),bucket[i].end());
                for(int j = 0;j<bucket[i].size();j++)
                {
                    res.push_back(bucket[i][j]);
                    if(res.size() == k)
                        return res;
                }
            }
        }
    }
};