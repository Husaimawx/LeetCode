// My code

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<vector<int>> tempres;
        
        vector<int> temp(26,0);
        vector<vector<int>> htable(strs.size(),temp);
        for(int i = 0; i<strs.size();i++)
        {
            for(int j = 0; j<strs[i].length();j++)
            {
                htable[i][strs[i][j]-'a']+=1;
            }
        }
        
        for(int i = 0; i<strs.size();i++)
        {
            insert(tempres, htable, i);
        }
        
        for(int i = 0; i<tempres.size();i++)
        {
            vector<string> temp;
            for(int j= 0;j<tempres[i].size();j++)
            {
			    temp.push_back(strs[tempres[i][j]]);
            }
            res.push_back(temp);
        }
        return res;
    }
    
    void insert(vector<vector<int>>& tempres, vector<vector<int>>& htable, int refer)
    {
        for(int i = 0;i<tempres.size();i++)
        {
            if(isSame(htable[tempres[i][0]],htable[refer]))
            {
                tempres[i].push_back(refer);
                return;
            }
        }
        vector<int> temp(1,refer);
        tempres.push_back(temp);
    }
    
    bool isSame(vector<int> a, vector<int> b)
    {
        for(int i = 0;i<26;i++)
        {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};

// Other people's code

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, int> m;
        std::vector<std::vector<std::string>> result;
        int index = 0;
        for (auto & s : strs) {
            auto w = s;
            std::sort(s.begin(), s.end());
            if (m.find(s) == m.end()) {
                m[s] = index++;
                result.emplace_back();
                result.back().push_back(std::move(w));
            }
            else {
                result[m[s]].push_back(std::move(w));
            }
        }
        return result;
    }
};