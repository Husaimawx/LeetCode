class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> M;
        for(int i = 0;i<order.size();i++) {
            M[order[i]] = i;
        }
        for(int i = 0;i+1<words.size();i++) {
            int m = min(words[i].size(),words[i+1].size());
            int j;
            for(j = 0;j<m;j++) {
                if(M[words[i][j]] < M[words[i+1][j]])
                    break;
                if(M[words[i][j]] > M[words[i+1][j]])
                    return false;
            }
            if(j == m && words[i+1].size() == m)
                return false;
        }
        return true;
    }
};