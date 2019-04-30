class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> V;
        V.resize(N);
        
        for(int i = 0;i<dislikes.size();i++) {
            V[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            V[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        map<int,int> cover;
        for(int i = 0;i < N;i++) {
            if(cover.count(i) != 0)
                continue;
            //cout << i;
            vector<int> lst(1, i);
            cover[i] = 1;
            int from = 0;
            int flag = 1;
            while(1) {
                int to = lst.size();
                if(from == to)
                    break;
                for(int j = from;j<to;j++) {
                    for(int k = 0;k<V[lst[j]].size();k++) {
                        if(cover.count(V[lst[j]][k]) == 0) {
                            lst.push_back(V[lst[j]][k]);
                            cover[V[lst[j]][k]] = 3-flag;
                        }
                        else if(cover[V[lst[j]][k]] == flag)
                            return false;
                    }
                }
                from = to;
                flag = 3-flag;
            }
        }
        return true;
    }
};