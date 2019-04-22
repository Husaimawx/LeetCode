class Solution {
vector<int> num{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
public:
    int racecar(int target) {
        if(target == 0)
            return 0;
        if(target == 1)
            return 1;
        if(target == 2)
            return 4;
        if(target == 3)
            return 2;
    
        vector<int> res(target+1, INT_MAX);
        res[1] = 1;
        res[2] = 4;
        res[3] = 2;
        for(int t = 4;t<=target;t++) {
            long base = 2;
            int k = 1;
            while(base*2 <= long(t)) {
                base *= 2;
                k += 1;
            }
            if(t == base*2-1)
                res[t] = k + 1;
            else {
                //cout << base << endl;
                res[t] = k + 2 + res[base*2-1-t];
                //cout << res[t];
                for(int i = 1;i<k+1;i++) {
                    for(int j = 0;j<i;j++) {
                        res[t] = min(res[t], 2+i+j+res[t-num[i]+num[j]]);
                    }
                }
            }
            cout << t << " " << res[t] << endl;
        }   
        
        return res[target];
    }
};