class Solution {
public:
    int checkRecord(int n) {
        if(n == 0)
            return 1;
        
        long long A=0,B=0,C=0,D=1,E=0,F=0;
        long long ta,tb,tc,td,te,tf;
        for(int i = 0;i<n;i++) {
            ta = A+B+C+D+E+F;
            tb = A;
            tc = B;
            td = D+E+F;
            te = D;
            tf = E;
            A = ta%1000000007;
            B = tb%1000000007;
            C = tc%1000000007;
            D = td%1000000007;
            E = te%1000000007;
            F = tf%1000000007;
        }
        
        return (A+B+C+D+E+F)%1000000007;
    }
};