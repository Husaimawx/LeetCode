class Solution {
public:
    int longestValidParentheses(string s) {
        map<int,int> M;
        vector<int> res(s.size(),0);
        
        for(int i = 1;i<s.size();i++) {
            if(s[i] == '(')
                res[i] = 0;
            else {
                int temp = 1;
                for(int j = i-1;j>=0;j--) {
                    if(M.count(j) != 0)
                        j = M[j];
                    else {
                        if(s[j] == ')')
                            temp+=1;
                        else
                            temp-=1;
                        if(temp == 0) {
                            M[i] = j;
                            if(j != 0)
                                res[i] = res[j-1]+i-j+1;
                            else
                                res[i] = i+1;
                            break;
                        }
                    }
                }
            }
        }
        
        int max = 0;
        for(int i = 0;i<s.size();i++)
            if(max < res[i])
                max = res[i];
        return max;
    }
};