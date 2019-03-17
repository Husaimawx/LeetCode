class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")
            return 0;
        map<vector<int>, int> M;
        for(int i = 0;i<deadends.size();i++) {
            vector<int> temp({deadends[i][0]-'0', deadends[i][1]-'0', deadends[i][2]-'0', deadends[i][3]-'0'});
            M[temp] = 1;
        }
        vector<int> tgt({target[0]-'0', target[1]-'0', target[2]-'0', target[3]-'0'});
        vector<int> start(4,0);
        vector<vector<int>> bfs;
        if(M.count(start) == 1)
            return -1;
        bfs.push_back(start);
        int from = 0;
        int res = 1;
        while(bfs.size() != from) {
            int to = bfs.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<4;j++) {
                    vector<int> temp(bfs[i]);
                    temp[j] = (temp[j]+1) % 10;
                    //cout << temp[0] << temp[1] << temp[2] << temp[3] << endl;
                    if(same(temp, tgt))
                        return res;
                    if(M.count(temp) == 0) {
                        M[temp] = 1;
                        bfs.push_back(temp);
                    }
                    temp[j] = (temp[j]+8) % 10;
                    //cout << temp[0] << temp[1] << temp[2] << temp[3] << endl;
                    if(same(temp, tgt))
                        return res;
                    if(M.count(temp) == 0) {
                        M[temp] = 1;
                        bfs.push_back(temp);
                    }
                }
            }
            from = to;
            res += 1;
        }
        return -1;
    }
    
    bool same(vector<int>& a, vector<int>& b) {
        for(int i = 0;i<4;i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};