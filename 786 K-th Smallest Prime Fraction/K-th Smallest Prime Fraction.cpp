class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        //if(K == 1)
        //    return vector<int>{A[0],A[A.size()-1]};
        double left = 0;
        double right = 1;
        double mid;
        while(1) {
            mid = (left + right)/2;
            vector<int> near(2,0);
            int num_left = auxPrime(A, mid, near);
            //cout << num_left << " " << mid << " " << near[0] << " " << near[1] << endl;
            if(num_left == K)
                return vector<int>{A[near[0]],A[near[1]]};
            if(num_left < K) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
    
    int auxPrime(vector<int>& A, double mid, vector<int>& near) {
        int res = 0;
        int i;
        for(i = 0;i<A.size();i++) {
            if(double(A[i])/double(A[A.size()-1]) > mid)
                break;
        }
        if(i == 0)
            return 0;
        i-=1;
        res += (i+1);
        near[0] = i;
        near[1] = A.size()-1;
        for(int j = A.size()-2;j>=1;j--) {
            while(double(A[i])/double(A[j]) > mid) {
                i--;
                if(i < 0) {
                    return res;
                }
            }
            res += (i+1);
            if(double(A[i])/double(A[j]) > double(A[near[0]])/double(A[near[1]])) {
                near[0] = i;
                near[1] = j;
            }
        }
        return res;
    }
};