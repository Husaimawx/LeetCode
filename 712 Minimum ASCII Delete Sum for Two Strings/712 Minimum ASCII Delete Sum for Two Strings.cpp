class Solution {
    int dim = 2000;
    unordered_map<int,int> M;
public:
    int minimumDeleteSum(string s1, string s2) {
        int res =  minaux(s1,s2,0,0);
        //for(auto i = M.begin();i != M.end();i++)
        //    cout << i->first << i->second << endl;
        return res;
    }
    
    int minaux(string& s1, string& s2, int from1, int from2) {
        if(M.count(dim*from1+from2) == 1) {
            return M[dim*from1+from2];
        }
        
        int res = 0;
        
        if(from1 == s1.size()) {
            for(int i = from2;i<s2.size();i++) {
                res += s2[i];
            }
            M[dim*from1+from2] = res;
            //cout << from1 << from2 << M[dim*from1+from2] << endl;
            return res;
        }
        if(from2 == s2.size()) {
            for(int i = from1;i<s1.size();i++) {
                res += s1[i];
            }
            M[dim*from1+from2] = res;
            //cout << from1 << from2 << M[dim*from1+from2] << endl;
            return res;            
        }
        
        if(s1[from1] == s2[from2]) {
            M[dim*from1+from2] = minaux(s1,s2,from1+1,from2+1);
            //cout << from1 << from2 << M[dim*from1+from2] << endl;
            return M[dim*from1+from2];
        }
        
        int res1 = minaux(s1,s2,from1,from2+1)+s2[from2];
        int res2 = minaux(s1,s2,from1+1, from2)+s1[from1];

        M[dim*from1+from2] = min(res1,res2);
        //cout << from1 << from2 << M[dim*from1+from2] << endl;
        return M[dim*from1+from2];
    }
};