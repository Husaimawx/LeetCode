class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> value(words.size(),0);
        
        for(int i = 0;i<words.size();i++)
        {
            for(int j = 0;j<words[i].size();j++)
            {
                if((value[i]&(1<<(words[i][j]-'a'))) == 0)
                    value[i]+=(1<<(words[i][j]-'a'));
            }
        }
        
        int res = 0;
        for(int i = 0;i<words.size();i++)
        {
            for(int j = i+1;j<words.size();j++)
            {
                if((value[i] & value[j]) == 0 && words[i].size()*words[j].size() > res)
                    res = words[i].size()*words[j].size();
            }
        }
        return res;
    }
};