class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<long> front(A.size(),A[0]);
        for(int i = 1;i<A.size();i++) {
            front[i] = (front[i-1]+A[i])%1000000007;
        }
        vector<long> back(A.size(),A[A.size()-1]);
        int j = A.size()-2;
        for(int i = 1;i<A.size();i++) {
            back[i] = (back[i-1]+A[j])%1000000007;
            j--;
        }
        
        vector<long> p2(1,1);
        long base = 1;
        for(int i = 1;i<A.size();i++) {
            base = (base*2)%1000000007;
            p2.push_back(base);
        }
        
        long res = 0;
        for(int i = 0;i+1<A.size();i++) {
            res = (res+(back[i]-front[i])*p2[A.size()-2-i])%1000000007;
        }
        return int(res);
    }
};