class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> v(26,0);
        int from = 0;
        while(from < p.size()) {
            int i;
            for(i = from+1;i<p.size();i++) {
                if((p[i-1]+1-p[i]) % 26 != 0)
                    break;
            }
            for(int j = from;j<min(i,from+26);j++) {
                v[p[j]-'a'] = max(v[p[j]-'a'],i-j);
            }
            from = i;
        }
        
        int res = 0;
        for(int i = 0;i<26;i++) {
            res+=v[i];
        }
        return res;
    }
};