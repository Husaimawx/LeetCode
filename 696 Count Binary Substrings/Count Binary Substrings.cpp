class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() == 0)
            return 0;
        
        vector<int> temp;
        int from = 0;
        while(from != s.size()) {
            int to;
            for(to = from+1;to < s.size();to++) {
                if(s[to] != s[from])
                    break;
            }
            temp.push_back(to-from);
            from = to;
        }
        
        int res = 0;
        for(int i = 0;i+1 < temp.size();i++) {
            res += min(temp[i],temp[i+1]);
        }
        return res;
    }
};