class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int,vector<int>> M;
        for(int i = 0;i<B.size();i++) {
            if(M.count(B[i]) == 0)
                M[B[i]] = vector<int>(1, i);
            else
                M[B[i]].push_back(i);
        }
        
        vector<int> key(A.size(), INT_MIN);
        sort(A.begin(),A.end());
        map<int,int> takeup;
        
        int from = 0;
        for(auto iter = M.begin();iter != M.end();iter++) {
            for(int i = 0;i<(iter->second).size();i++) {
                //cout << iter->first << endl;
                while(from != A.size() && A[from] <= iter->first) from++;
                //cout << from;
                if(from == A.size()) {
                    //cout << endl;
                    //cout << takeup.size() << endl;
                    //for(int i = 0;i<key.size();i++)
                    //    cout << key[i] << " ";
                    from = 0;
                    for(int i = 0;i<A.size();i++) {
                        if(takeup.count(i) != 0)
                            continue;
                        while(key[from] != INT_MIN) from++;
                        key[from] = A[i];
                    }
                    return key;
                }
                key[(iter->second)[i]] = A[from];
                takeup[from] = 1;
                from++;
            }
        }

        return key;
    }
};