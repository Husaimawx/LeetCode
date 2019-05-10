class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) {
            vector<int> res{1,2,3,4,5,6,7,8,9,0};
            return res;
        }
        vector<int> temp = numsSameConsecDiff(N-1,K);
        if(N == 2)
            temp.resize(9);
        vector<int> res;
        for(int i = 0;i<temp.size();i++) {
            int last = temp[i] % 10;
            if(last >= K)
                res.push_back(temp[i]*10+last-K);
            if(K != 0 && last + K < 10)
                res.push_back(temp[i]*10+last+K);
        }
        return res;
    }
};