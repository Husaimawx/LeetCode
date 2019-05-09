class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int time = 0;
        vector<int> B;
        vector<int> C;
        for(int i = 0;i<A.size();i++) {
            if(A[i] == 0)
                time += 1;
            else if(A[i] < 0)
                B.push_back(A[i]*-1);
            else
                C.push_back(A[i]);
        }
        return (time % 2 == 0 && sub(B) && sub(C));
    }
    bool sub(vector<int>& A) {
        if(A.size() % 2 == 1)
            return false;
        map<int,int> M;
        for(int i = 0;i<A.size();i++) {
            M[A[i]] += 1;
        }
        //for(auto iter = M.begin();iter != M.end();iter++) {
        //    cout << iter->first << iter->second << endl;   
        //}
        for(auto iter = M.begin();iter != M.end();iter++) {
            if(iter->second == 0)
                continue;
            if(M[(iter->first)*2] < iter->second)
                return false;
            M[(iter->first)*2] -= iter->second;
        }
        return true;
    }
};