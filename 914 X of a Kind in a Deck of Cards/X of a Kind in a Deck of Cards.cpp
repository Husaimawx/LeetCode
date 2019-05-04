class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> M;
        vector<int> prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        for(int i = 0;i<deck.size();i++) {
            if(M.count(deck[i]) == 0)
                M[deck[i]] = 1;
            else
                M[deck[i]] += 1;
        }
        vector<int> v;
        int m = INT_MAX;
        for(auto iter = M.begin();iter != M.end();iter++) {
            v.push_back(iter->second);
            m = min(m,iter->second);
            //cout << iter->second << endl;
        }
        if(m == 1)
            return false;
        if(v.size() == 1) 
            return true;
        //for(int i = 0;i<v.size();i++)
        //    cout << v[i];

        for(int i = 0;i<prime.size() && prime[i] <= m;i++) {
            int j;
            for(j = 0;j<v.size();j++) {
                if(v[j] % prime[i] != 0)
                    break;
            }
            
            if(j == v.size()) {
                return true;
            }
        }
        for(int j = 0;j<v.size();j++) {
            if(v[j] % m != 0)
                return false;
        }
        return true;
    }
};