class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int> v(1,0);
        int res = 0;
        for(int i = 1;i<A.size();i++) {
            //if(i+1 == A.size()) {
            //    for(int e = 0;e<v.size();e++)
            //        cout << v[e];
            //}
            if(A[i] < A[v[v.size()-1]])
                v.push_back(i);
            else {
                int from = 0;
                int to = v.size()-1;
                while(from < to) {
                    int mid = (from+to)/2;
                    if(A[v[mid]]==A[i]) {
                        from = mid;
                        break;
                    } else if(A[v[mid]]<A[i]){
                        to = mid;
                    } else {
                        from = mid+1;
                    }
                }
                res = max(res, i-v[from]); 
            }
        }
        return res;
    }
};