class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long res = A[0];
        stack<pair<int,int>> num;
        stack<long> sum;
        num.push(pair<int,int>(A[0],0));
        sum.push(A[0]);
        for(int i = 1;i<A.size();i++) {
            while(num.size() != 0) {
                if(num.top().first >= A[i]) {
                    num.pop();
                    sum.pop();
                }
                else {
                    sum.push((sum.top()+A[i]*(i-num.top().second))%1000000007);
                    num.push(pair<int,int>(A[i],i));
                    break;
                }
            }
            if(num.size() == 0) {
                num.push(pair<int,int>(A[i],i));
                sum.push(A[i]*(i+1)%1000000007);
            }
            res = (res+sum.top())%1000000007;
        }
        
        return int(res);
    }
};