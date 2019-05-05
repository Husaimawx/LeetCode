class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>> n = convert(name);
        vector<pair<char,int>> t = convert(typed);
        //for(auto iter = n.begin();iter != n.end();iter++) {
        //    cout << iter->first << iter->second << endl;
        //}
        //cout << endl;
        //for(auto iter = t.begin();iter != t.end();iter++) {
        //    cout << iter->first << iter->second << endl;
        //}
        if(n.size() != t.size())
            return false;
        for(int i = 0;i<n.size();i++) {
            if(n[i].first != t[i].first || n[i].second > t[i].second)
                return false;
        }
        return true;
    }
    
    vector<pair<char,int>> convert(string& name) {
        vector<pair<char,int>> res;
        int from = 0;
        while(from != name.size()) {
            int to;
            for(to = from+1;to < name.size();to++) {
                if(name[to] != name[from])
                    break;
            }
            res.push_back(pair<char,int>(name[from],to-from));
            from = to;
        }
        return res;
    }
};