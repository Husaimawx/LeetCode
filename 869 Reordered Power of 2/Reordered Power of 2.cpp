class Solution {
public:
    bool reorderedPowerOf2(int N) {
        map<vector<int>,int> M;
        long res = 1;
        while(res < 1000000000) {
            M[convert(res)] = 1;
            res *= 2;
        }

        return M.count(convert(N));
    }
    
    vector<int> convert(int n) {
        vector<int> v(10,0);
        while(n != 0) {
            v[n%10] += 1;
            n/=10;
        }
        return v;
    }
};