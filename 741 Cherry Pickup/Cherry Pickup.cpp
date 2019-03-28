class Solution {
    int n;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> temp(n,-1);
        vector<vector<int>> temp2(n, temp);
        vector<vector<vector<int>>> mem(n, temp2);
        
        for(int i = 2*n-2;i>n-1;i--) {
            for(int j=n-1;j>=i-n+1;j--) {
                // grid[j][i-j]
                // mem[j][i-j][k]
                for(int k = j;k>=i-n-1;k--) {
                    if(grid[j][i-j] == -1 || grid[k][i-k] == -1)
                        continue;
                    int res;
                    if(j != k)
                        res = grid[j][i-j] + grid[k][i-k];
                    else
                        res = grid[j][i-j];
                    int a = check(j+1, i-j, k, grid, mem);
                    int b = check(j+1, i-j, k+1, grid, mem);
                    int c = check(j, i-j+1, k, grid, mem);
                    int d = check(j, i-j+1, k+1, grid, mem);
                    mem[j][i-j][k] = mymax(a,b,c,d)+res;
                }
            }
        }
        for(int i = n-1;i>=0;i--) {
            for(int j = j;j>=0;j--) {
                // grid[j][i-j]
                for(int k = j;k>=0;k--) {
                    if(grid[j][i-j] == -1 || grid[k][i-k] == -1)
                        continue;
                    int res;
                    if(j != k)
                        res = grid[j][i-j] + grid[k][i-k];
                    else
                        res = grid[j][i-j];
                    int a = check(j+1, i-j, k, grid, mem);
                    int b = check(j+1, i-j, k+1, grid, mem);
                    int c = check(j, i-j+1, k, grid, mem);
                    int d = check(j, i-j+1, k+1, grid, mem);
                    mem[j][i-j][k] = mymax(a,b,c,d)+res;
                }
            }
        }
        return max(0,mem[0][0][0]);
    }
    
    int check(int a, int b, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& mem) {
        int d = a+b-c;
        if(0>a || a>=n || 0>b || b>=n || 0>c || c>=n || 0>d || d>=n)
            return -1;
        if(grid[a][b] == -1 || grid[c][d] == -1)
            return -1;
        return mem[a][b][c];
    }
    
    int mymax(int a, int b, int c, int d) {
        int t1 = max(a,b);
        int t2 = max(c,d);
        return max(t1,t2);
    }
};