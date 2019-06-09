class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60);
        for(int i = 0;i<time.size();i++) {
            v[time[i]%60]+=1;
        }
        
        int res = 0;
        res += (v[0]-1)*v[0]/2;
        res += (v[30]-1)*v[30]/2;
        for(int i = 1;i<30;i++) {
            res += v[i]*v[60-i];
        }
        
        return res;
    }
};