class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> v(A.size(), vector<int>(26,0));
        for(int i = 0;i<A.size();i++) {
            for(int j = 0;j<A[i].size();j++) {
                v[i][A[i][j]-'a'] += 1;
            }
        }
        for(int i = 0;i<3;i++) {
            for(int j = 0;j<26;j++) {
                cout << v[i][j];
            }
            cout << endl;
        }
        vector<string> res;
        if(A.size() == 0)
            return res;
        for(int i = 0;i<26;i++) {
            int base = INT_MAX;
            for(int j = 0;j<A.size();j++) {
                if(base > v[j][i])
                    base = v[j][i];
            }
            string temp(1,'a'+i);
            for(int t = 0;t<base;t++)
                res.push_back(temp);
        }
        return res;
    }
};