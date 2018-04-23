class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int lenNow;
        int from;
        int temp;
        for(lenNow = len, from = 0; lenNow>1; lenNow-=2)
        {
            for(int i = 0; i<len-1-2*from; i++)
            {
                temp = matrix[from][from+i];
                matrix[from][from+i] = matrix[from+lenNow-1-i][from]; 
                matrix[from+lenNow-1-i][from] = matrix[from+lenNow-1][from+lenNow-1-i]; 
                matrix[from+lenNow-1][from+lenNow-1-i] = matrix[from+i][from+lenNow-1];
                matrix[from+i][from+lenNow-1] = temp;
            }
            from++;
        }
    }
};