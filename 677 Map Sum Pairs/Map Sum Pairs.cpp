class MapSum {
    unordered_map<string,int> M;
    unordered_map<string,int> data;
public:
    /** Initialize your data structure here. */
    MapSum() {
        M.empty();
        data.empty();
    }
    
    void insert(string key, int val) {
        if(data.count(key) != 0) {
            val -= data[key];
        }
        data[key] = val;
        
        string t = "";
        M[t] += val;
        for(int i = 0;i<key.size();i++) {
            t += key[i];
            M[t] += val;
        }
    }
    
    int sum(string prefix) {
        return M[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */