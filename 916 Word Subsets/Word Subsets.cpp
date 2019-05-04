class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> pat(26,0);
        for(int i = 0;i<B.size();i++) {
            vector<int> temp = convert(B[i]);
            for(int j = 0;j<26;j++) {
                pat[j] = max(pat[j],temp[j]);
            }
        }
        
        //for(int i = 0;i<26;i++) {
        //    cout << pat[i];
        //}
        
        vector<string> res;
        for(int i = 0;i<A.size();i++) {
            vector<int> temp = convert(A[i]);
            int j = 0;
            for(j = 0;j<26;j++) {
                if(temp[j] < pat[j])
                    break;
            }
            if(j == 26)
                res.push_back(A[i]);
        }
        return res;
    }
    
    vector<int> convert(string& A) {
        vector<int> res(26,0);
        for(int i = 0;i<A.size();i++) {
            res[A[i]-'a'] += 1;
        }
        return res;
    }
};