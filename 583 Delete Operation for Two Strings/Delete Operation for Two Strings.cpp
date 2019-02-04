class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)
            return word2.size();
        
        if(word2.size() == 0)
            return word1.size();
        
        vector<int> temp(word2.size()+1,0);
        vector<vector<int>> res(word1.size()+1,temp);
        
        for(int i = word1.size()-1;i>=0;i--) {
            for(int j = word2.size()-1;j>=0;j--) {
                int res1 = res[i+1][j];
                int t;
                int res2 = 0;
                for(t = j;t<word2.size();t++) {
                    if(word1[i] == word2[t])
                        break;
                }
                if(t != word2.size())
                    res2 = 1+res[i+1][t+1];
                
                res[i][j] = max(res1, res2);
            }
        }
        return word1.size() + word2.size() - 2*res[0][0];
    }
};