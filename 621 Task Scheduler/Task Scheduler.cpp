class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> M;
        for(int i = 'A';i<'Z';i++) {
            M[i] = INT_MIN;
        }
        
        vector<int> num(26,0);
        for(int i = 0;i<tasks.size();i++) {
            num[tasks[i]-'A'] ++;
        }

        int res = 0;
        for(int i = 0;i<tasks.size();i++) {
            int maxpos = -1;
            int maxnum = 0;
            int j;
            for(j = 0;j<26;j++) {
                if(M[j+'A'] +n >= res)
                    continue;
                if(num[j] > maxnum) {
                    maxpos = j;
                    maxnum = num[j];
                }
            }
           
            if(maxpos == -1) {
                res++;
                i--;
            } else {
                num[maxpos]-=1;
                M['A'+maxpos] = res;
                res++;
            }
        }
        return res;
    }
};