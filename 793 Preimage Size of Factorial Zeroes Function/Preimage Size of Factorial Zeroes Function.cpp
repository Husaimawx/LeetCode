class Solution {
public:
    int preimageSizeFZF(int K) {
        if(K == 0)
            return 5;
        long from = 4*long(K)+1;
        long to = 5*long(K);
        
        long mid;
        while(from <= to) {
            mid = (from+to)/2;
            int temp = check(mid);
            if(temp == K)
                break;
            else if(temp < K) {
                from = mid+1;
            } else {
                to = mid-1;
            }
        }
        if(from <= to)
            return 5;
        return 0;
    }
    
    int check(long N) {
        int res = 0;
        N /= 5;
        while(N != 0) {
            res += N;
            N /= 5; 
        }
        return res;
    }
};