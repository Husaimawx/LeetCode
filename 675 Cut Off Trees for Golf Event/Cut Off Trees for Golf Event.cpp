class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> trees;
        for(int i = 0;i<forest.size();i++) {
            for(int j = 0;j<forest[0].size();j++) {
                if(forest[i][j] > 1) {
                    vector<int> temp({forest[i][j],i,j});
                    trees.push_back(temp);
                }
            }
        }
        sort(trees.begin(),trees.end());
        int res = 0;
        for(int i = 0;i<trees.size();i++) {
            if(i == 0) {
                int temp2 = distance(forest, 0, 0, trees[0][1], trees[0][2]);
                if(temp2 == -1)
                    return -1;
                else
                    res += temp2;
            } else {
                int temp2 = distance(forest, trees[i-1][1], trees[i-1][2], trees[i][1], trees[i][2]);
                if(temp2 == -1)
                    return -1;
                else
                    res += temp2;
            }
        }
        return res;
    }
    
    // BFS to find shortest path to next tree; if cannot reach next tree, return -1
    int distance(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> myq;
        myq.push({sr, sc}); 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!myq.empty()) {
            step++;
            int sz = myq.size();
            for (int i = 0; i < sz; i++) {
                int row = myq.front().first, col = myq.front().second;
                myq.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i], c = col + dir[i+1];
                    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == er && c == ec) return step;
                    visited[r][c] = 1;
                    myq.push({r, c});
                }
            }
        }
        return -1;
    }
};