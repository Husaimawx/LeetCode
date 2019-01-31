class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)
            return 0;
        
        int* p = new int[s.size()];
        for(int i = 0;i<s.size();i++)
            p[i] = 1;
        
        int* q = new int[s.size()];
        for(int i = 0;i<s.size();i++)
            q[i] = 1;
        
        for(int i = 1;i<s.size();i++) {
            for(int j = i-1;j>=0;j--) {
                if(s[i] != s[j]) {
                    q[i] = max(p[j],p[j+1]);
                } else {
                    if(j+1 == i)
                        q[i] = 2;
                    else
                        q[i] = p[i+1]+2;
                }
            }
            int* temp = p;
            p = q;
            q = temp;
        }
        
        for(int i = 0;i<5;i++) {
            cout << p[i];
        }
        for(int i = 0;i<5;i++) {
            cout << q[i];
        }
        return p[0];
    }
};