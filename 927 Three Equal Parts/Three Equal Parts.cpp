class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        map<int,int> M;
        vector<int> res(2,0);
        int base = 0;
        for(int i = 0;i<A.size();i++) {
            if(A[i] == 1) {
                M[base] = i;
                base += 1;
            }
        }
        if(base == 0) {
            res[1] = A.size()-1;
            return res;
        }
        if(base % 3 != 0) {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        int f1 = M[0];
        int f2 = M[base/3];
        int f3 = M[base*2/3];
        //cout << base << f1 << f2 << f3;
        if((A.size()-f3)*3>A.size()-M[0]) {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        for(int i = 0;i<A.size()-f3;i++) {
            if(A[f1+i] != A[f2+i] || A[f2+i] != A[f3+i]) {
                res[0] = -1;
                res[1] = -1;
                return res;   
            }
        }
        int length = A.size()-f3;
        res[0] = f1+length-1;
        res[1] = f2+length;
        return res;
    }
};