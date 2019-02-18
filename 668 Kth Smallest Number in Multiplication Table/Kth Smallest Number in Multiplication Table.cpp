class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long from = 0, to = m*n;
        while(from < to) {
            long long mid = (from+to)/2;
            vector<int> ans = check(m,n,mid);
            if(ans[0] < k && k <= ans[1])
                return mid;
            if(k > ans[1])
                from = mid+1;
            else
                to = mid-1;
        }
        return from;
    }
    
    vector<int> check(int m, int n, long long mid) {
        vector<int> res(2,0);
        for(int i = 0;i<m;i++) {
            res[1] += min((long long)(n),mid/(i+1));
            res[0] += min((long long)(n),(mid-1)/(i+1));
        }
        return res;
    }
};