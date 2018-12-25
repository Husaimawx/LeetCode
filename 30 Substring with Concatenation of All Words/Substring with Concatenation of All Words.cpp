class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size() == 0 || s.size() == 0)
            return res;
        
        unordered_map<string, int> M;
        for(int i = 0;i<words.size();i++) {
            if(M.count(words[i]) == 0)
                M[words[i]] = 1;
            else {
                M[words[i]] = M[words[i]] + 1;
            }
        }
        
        int step = words[0].size();
        
        for(int from = 0;from<step;from++) {
            unordered_map<string, int> M1 = M;
            int start = from, end = from;
            while(start + words.size()*step <= s.size()) {
                string temp = s.substr(end,step);
                if(M.count(temp) == 0) {
                    end = end + step;
                    start = end;  
                    M1 = M;
                } else {
                    if(M1[temp] == 0) {
                        end += step;
                        while(temp != s.substr(start,step)) {
                            M1[s.substr(start,step)] += 1;
                            start += step;
                        }
                        start += step;
                    } else {
                        M1[temp] -= 1;
                        end += step;
                        if(end-start == words.size()*step) {
                            res.push_back(start);
                            M1[s.substr(start,step)] += 1;
                            start += step;
                        }
                    }
                }
            }
        }
        return res;
    }

};