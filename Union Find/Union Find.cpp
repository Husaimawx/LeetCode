// base version
class Solution {
    vector<int> parent;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string,string> owner;
        unordered_map<string, int> index;
        unordered_map<int, string> reverse;
        
        // collect all the string names
        for(int i = 0;i<acts.size();i++) {
            for(int j = 1;j<acts[i].size();j++) {
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        // get size
        int sz = owner.size();
        
        // built index
        int ind = 0;
        for(auto iter = owner.begin();iter!=owner.end();iter++) {
            index[iter->first] = ind;
            reverse[ind] = iter->first;
            ind++;
        }
        
        // init parent vector
        parent.resize(sz);
        for(int i = 0;i<sz;i++) {
            parent[i] = i;
        }
        
        // do all updates
        // compute all pairs (num1, num2) (num1, num3) (num1, num4) ......
        for(int i = 0;i<acts.size();i++) {
            //int ancestor = find(index[acts[i][1]]);
            int ancestor = index[acts[i][1]];
            for(int j = 2;j<acts[i].size();j++) {
                int chose = index[acts[i][j]];
                union_(chose, ancestor);
            }
        }
        
        // construct results
        unordered_map<string, vector<string>> M;
        for(int i = 0;i<sz;i++) {
            int ancestor = find(i);
            if(M.count(reverse[ancestor]) == 0)
                M[reverse[ancestor]] = vector<string>(1,owner[reverse[ancestor]]);
            M[reverse[ancestor]].push_back(reverse[i]);
        }
        vector<vector<string>> res;
        for(auto it:M) {
            res.push_back(it.second);
            sort(res[res.size()-1].begin()+1, res[res.size()-1].end());
        }
        
        return res;
    }
    
    int find(int index) {
        return index == parent[index] ? index : find(parent[index]);
    }
    
    void union_(int x, int y) {
        parent[find(x)] = find(y);
    }
};

// using faltten trick
class Solution {
    vector<int> parent;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string,string> owner;
        unordered_map<string, int> index;
        unordered_map<int, string> reverse;
        
        // collect all the string names
        for(int i = 0;i<acts.size();i++) {
            for(int j = 1;j<acts[i].size();j++) {
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        // get size
        int sz = owner.size();
        
        // built index
        int ind = 0;
        for(auto iter = owner.begin();iter!=owner.end();iter++) {
            index[iter->first] = ind;
            reverse[ind] = iter->first;
            ind++;
        }
        
        // init parent vector
        parent.resize(sz);
        for(int i = 0;i<sz;i++) {
            parent[i] = i;
        }
        
        // do all updates
        // compute all pairs (num1, num2) (num1, num3) (num1, num4) ......
        for(int i = 0;i<acts.size();i++) {
            // both two following are OK
            vector<int> temp = find(index[acts[i][1]]);
            int ancestor = temp[temp.size()-1];
            //int ancestor = index[acts[i][1]];
            for(int j = 2;j<acts[i].size();j++) {
                int chose = index[acts[i][j]];
                union_(chose, ancestor);
            }
        }
        
        // construct results
        unordered_map<string, vector<string>> M;
        for(int i = 0;i<sz;i++) {
            vector<int> temp = find(i);
            int ancestor = temp[temp.size()-1];
            if(M.count(reverse[ancestor]) == 0)
                M[reverse[ancestor]] = vector<string>(1,owner[reverse[ancestor]]);
            M[reverse[ancestor]].push_back(reverse[i]);
        }
        vector<vector<string>> res;
        for(auto it:M) {
            res.push_back(it.second);
            sort(res[res.size()-1].begin()+1, res[res.size()-1].end());
        }
        
        return res;
    }
    
    //int find(int index) {
    //    return index == parent[index] ? index : find(parent[index]);
    //}
    vector<int> find(int index) {
        vector<int> list;
        while(index != parent[index]) {
            list.push_back(index);
            index = parent[index];
        }
        list.push_back(index);
        return list;
    }
    
    void union_(int x, int y) {
        vector<int> t1 = find(x);
        vector<int> t2 = find(y);
        for(int i = 0;i<t1.size();i++)
            parent[t1[i]] = t2[t2.size()-1];
    }
};

// free style version
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