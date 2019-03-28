class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        
        string target = "123450";
        string begin = to_string(b[0][0])+to_string(b[0][1])+to_string(b[0][2])+
            to_string(b[1][0])+to_string(b[1][1])+to_string(b[1][2]);
        if(target == begin)
            return 0;
        vector<vector<int>> move({{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}});
        
        vector<string> q;
        unordered_map<string, int> m;
        q.push_back(begin);
        m[begin] = 0;
        int from = 0;
        while(from < q.size()) {
            int to = q.size();
            for(int i = from;i<to;i++) {
                int zero=(int)q[i].find("0");
                for(int j = 0;j<move[zero].size();j++) {
                    string temp = q[i];
                    swap(temp[zero], temp[move[zero][j]]);
                    if(m.count(temp) == 0)
                    {
                        q.push_back(temp);
                        //cout << temp << endl;
                        m[temp] = m[q[i]]+1;
                        if(temp == target)
                            return m[temp];
                    }
                }
            }
            from = to;
        }
        
        return -1;
    }
};