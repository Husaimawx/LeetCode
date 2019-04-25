class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0) {
            return 1;
        }
        vector<double> res(K+W, 0);
        res[0] = 1;
        double sum = 0.0;
        for(int i = 1;i<K+W;i++) {
            if(i <= K)
                sum += res[i-1]/W;
            if(i > W)
                sum -= res[i-W-1]/W;
            res[i] = sum;
        } 
        double ret = 0;
        for(int i = K;i<=N;i++) {
            ret += res[i];
        }
        return ret;
    }
};