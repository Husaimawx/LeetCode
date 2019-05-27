class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> M;
        for(int i = 0;i<words.size();i++) {
            if(words[i] != "") {
                string temp = words[i];
                reverse(temp.begin(),temp.end());
                M[temp] = i;
            }
            else {
                for(int j = 0;j<words.size();j++) {
                    if(j == i)
                        continue;
                    if(check(words[j])) {
                        vector<int> temp{i,j};
                        res.push_back(temp);
                        temp[0] = j;
                        temp[1] = i;
                        res.push_back(temp);
                    }
                }
            }
        }
        
        for(int i = 0;i<words.size();i++) {
            if(words[i] == "")
                continue;
            for(int j = 0;j<words[i].size();j++) {
                if(M.count(words[i].substr(0,j)) != 0) {
                    string temp = words[i].substr(j,words[i].size()-j);
                    if(check(temp)) {
                        vector<int> temp{i,M[words[i].substr(0,j)]};
                        if(temp[0] != temp[1])
                            res.push_back(temp);
                    }
                }
                if(M.count(words[i].substr(j,words[i].size()-j)) != 0) {
                    string temp = words[i].substr(0,j);
                    if(check(temp)) {
                        vector<int> temp{M[words[i].substr(j,words[i].size()-j)],i};
                        if(temp[0] != temp[1])
                            res.push_back(temp);
                    }
                }
            }
        }
        
        return res;
    }
    
    bool check(string& s) {
        if(s.size() < 2)
            return true;
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};