class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1)
            return 1;
        map<int,int> count;
        set<int> filter;
        
        for(int i = 0;i<trust.size();i++) {
            filter.insert(trust[i][0]);
            count[trust[i][1]]+=1;
        }
        //for(auto iter = count.begin();iter!=count.end();iter++) {
        //    cout << iter->first << iter->second << endl;
        //}
        //for(auto iter = filter.begin();iter!= filter.end();iter++)
        //    cout << *iter;
        vector<int> res;
        for(auto iter = count.begin();iter!=count.end();iter++) {
            if(iter->second == N-1 && filter.count(iter->first) == 0)
                res.push_back(iter->first);
        }
        if(res.size() != 1)
            return -1;
        return res[0];
    }
};