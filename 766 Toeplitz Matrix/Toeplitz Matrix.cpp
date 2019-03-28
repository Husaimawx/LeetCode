class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = m-1;i>=(1-n);i--) {
            int yf = max(0,0-i);
            int yt = min(n-1, m-1-i);
            for(int y = yf+1;y<=yt;y++) {
                //cout << y+i << " " << y << endl;
                if(matrix[y+i][y] != matrix[y+i-1][y-1])
                    return false;
            }
        }
        return true;
    }
};