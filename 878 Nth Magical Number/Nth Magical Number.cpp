class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int base = gcd(A,B);
        int res = calculate(N,A/base,B/base);
        res = int(long(res)*long(base)%(1000000007));
        return res;
    }
    
    int gcd(int A, int B) {
        while(A != 0 && B != 0) {
            if(A>=B)
                A-=B;
            else
                B-=A;
        }
        return (A+B);
    }
    
    int calculate(int N, int A, int B) {
        long mul = long(A)*long(B);
        long time = long(A)+long(B)-1;
        long res = ((N/time)*mul)%1000000007;
        long remain = N % time;
        if(remain == 0)
            return int(res);
        int a = 1;
        int b = 1;
        vector<long> v;
        while(1) {
            if(long(A)*a > long(B)*b) {
                v.push_back(long(B)*b);
                b++;
            } else {
                v.push_back(long(A)*a);
                a++;
            }
            if(v.size() >= remain)
                return int((res + v[remain-1])%1000000007);
        }
    }
};