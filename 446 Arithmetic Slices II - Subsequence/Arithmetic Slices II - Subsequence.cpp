class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        
        vector<long long> B;
        for(int i = 0;i<A.size();i++) {
            B.push_back((long)(A[i]));
        }
        
        
        map<pair<int,long>,pair<int,int>> store;
        
        int res = 0;
        
        for(int i = 0;i<A.size();i++) {
            for(int j = i-1;j>=0;j--) {
                if(store.count(pair<int,long>(j,B[i]-B[j])) == 0) {
                    if(store.count(pair<int,long>(i,B[i]-B[j])) == 0)
                        store[pair<int,long>(i,B[i]-B[j])] = pair<int,int>(1,0);
                    else
                        store[pair<int,long>(i,B[i]-B[j])].first += 1;
                } else {
                    if(store.count(pair<int,long>(i,B[i]-B[j])) == 0) {
                        pair<int,long> temp = store[pair<int,long>(j,B[i]-B[j])];
                        store[pair<int,long>(i,B[i]-B[j])] = pair<int,int>(1,temp.second+temp.first);
                        res += (temp.first+temp.second);
                    } else {
                        pair<int,long> temp = store[pair<int,long>(j,B[i]-B[j])];
                        store[pair<int,long>(i,B[i]-B[j])].first += 1;
                        store[pair<int,long>(i,B[i]-B[j])].second += (temp.second+temp.first);   
                        res += (temp.first+temp.second);
                    }
                    
                }
            }
        }
        return res;
    }
};