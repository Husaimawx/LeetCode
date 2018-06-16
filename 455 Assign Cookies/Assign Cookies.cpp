class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i,j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(i = 0;i<g.size();i++)
        {
            while(j<s.size())
            {
                if(g[i] <= s[j])
                    break;
                j++;
            }
            if(j == s.size())
                break;
            else
                j++;
        }
        return i;
    }
};