class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string,string> owner;
        unordered_map<string,string> parent;
        
        for(int i = 0;i<acts.size();i++) {
            for(int j = 1;j<acts[i].size();j++) {
                parent[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        for(int i = 0;i<acts.size();i++) {
            string ancestor = find(acts[i][1], parent);
            for(int j = 2;j<acts[i].size();j++) {
                parent[find(acts[i][j], parent)] = ancestor;
            }
        }
        
        unordered_map<string, set<string>> M;
        for(int i = 0;i<acts.size();i++) {
            for(int j = 1;j<acts[i].size();j++) {
                M[find(acts[i][j], parent)].insert(acts[i][j]);
            }
        }
        

        vector<vector<string>> res;
        for (auto p : M) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }

        
        return res;
    }
    
    string find(string s, unordered_map<string,string>& parent) {
        return s == parent[s] ? s : find(parent[s],parent);
    }
};