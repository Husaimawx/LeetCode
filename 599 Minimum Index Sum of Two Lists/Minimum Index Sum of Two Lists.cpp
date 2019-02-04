class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        if(list1.size() == 0 || list2.size() == 0)
            return res;
        
        map<string, int> M;
        for(int i = 0;i<list1.size();i++) {
            M[list1[i]] = i;
        }
        
        map<string, int> M2;
        for(int i = 0;i<list2.size();i++) {
            if(M.count(list2[i]) != 0) {
                M2[list2[i]] = M[list2[i]]+i;
            }
        }
        
        int min = INT_MAX;
        for(auto iter = M2.begin();iter != M2.end();iter++) {
            if(min > iter->second) {
                min = iter->second;
                res.resize(0);
                res.push_back(iter->first);
            } else if(min == iter->second) {
                res.push_back(iter->first);
            } 
        }
        return res;
    }
};