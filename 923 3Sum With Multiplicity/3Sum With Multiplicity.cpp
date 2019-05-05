class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        vector<int> time(101,0);
        for(int i = 0;i<A.size();i++) {
            time[A[i]] += 1;
        }
        long res = 0;
        for(int i = min(100,target);i>=0;i--) {
            for(int j = min(target-i,i);j>=0;j--) {
                int t = target-i-j;
                if(t < 0 || t > j)
                    continue;
                if(i == t) {
                    res = (res + com1(time[i])) % 1000000007; 
                }
                else if(i == j) {
                    res = (res + long(time[t]) * com2(time[i])) % 1000000007; 
                }
                else if(j == t) {
                    res = (res + long(time[i]) * com2(time[j])) % 1000000007; 
                }
                else
                    res = (res + (long)time[i]*(long)time[j]*(long)time[t]) % 1000000007; 
            }
        }
        return int(res);
    }
    
    long com1(int t) {
        if(t < 3)
            return 0;
        return long(t)*long(t-1)*long(t-2)/6;
    }
    
    long com2(int t) {
        if(t < 2)
            return 0;
        return long(t)*long(t-1)/2;
    }
};