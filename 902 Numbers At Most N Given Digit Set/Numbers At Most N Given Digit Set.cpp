class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> dig(10,0);
        map<int,int> M;
        for(int i = 0;i<D.size();i++) {
            dig[D[i][0]-'0'] += 1;
            M[D[i][0]-'0'] = 1;
        }
        for(int i = 2;i<10;i++) {
            dig[i]+=dig[i-1];
        }
        vector<int> num;
        while(N != 0) {
            num.push_back(N % 10);
            N/=10;
        }
        int time = num.size()-1;
        int res = 0;
        for(int i = 1;i<=time;i++) {
            res += pow(D.size(),i);
        }

        for(int i = num.size()-1;i>=0;i--) {
            if(num[i] == 0)
                return res;
            int a = dig[num[i]-1];
            res += a*pow(D.size(),i);
            if(M.count(num[i]) == 0) {
                return res;
            }
            if(i == 0)
                res += 1;
        }
        return res;
    }
};