class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> next(s2.size());
        for(int i = 0;i<s2.size();i++) {
            int from = i;
            for(int j = 0;j<s1.size();j++) {
                if(s2[from%(s2.size())] == s1[j])
                    from += 1;
            }
            next[i] = from-i;
        }
        int res = 0;
        int now = 0;
        for(int i = 0;i<n1;i++) {
            res += next[now];
            now += next[now];
            now = now % s2.size();
        }
        return res / (n2*s2.size());
    }
};