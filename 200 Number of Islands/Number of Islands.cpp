class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int count = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    BFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void BFS(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        grid[i][j] = '0';
        int t1,t2;
        while(!q.empty())
        {
            t1 = q.front().first;
            t2 = q.front().second;
            q.pop();
            
            if(0<=t1+1 && t1+1<grid.size() && 0<=t2 && t2<grid[0].size() && grid[t1+1][t2] == '1')
            {
                q.push(make_pair(t1+1,t2));
                grid[t1+1][t2] = '0';
            }
            if(0<=t1-1 && t1-1<grid.size() && 0<=t2 && t2<grid[0].size() && grid[t1-1][t2] == '1')
            {
                q.push(make_pair(t1-1,t2));
                grid[t1-1][t2] = '0';
            }
            if(0<=t1 && t1<grid.size() && 0<=t2+1 && t2+1<grid[0].size() && grid[t1][t2+1] == '1')
            {
                q.push(make_pair(t1,t2+1));
                grid[t1][t2+1] = '0';
            }
            if(0<=t1 && t1<grid.size() && 0<=t2-1 && t2-1<grid[0].size() && grid[t1][t2-1] == '1')
            {
                q.push(make_pair(t1,t2-1));
                grid[t1][t2-1] = '0';
            }
        }
    }
};