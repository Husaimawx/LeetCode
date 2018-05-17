class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int size = matrix.size()*matrix[0].size();
        
        int from = 0,to = size-1;
        int temp;
        while(from <=to)
        {
            temp = (from + to) / 2;
            if(matrix[temp/matrix[0].size()][temp%matrix[0].size()] == target)
                return true;
            else if(matrix[temp/matrix[0].size()][temp%matrix[0].size()] < target)
            {
                from = temp+1;
            }
            else
            {
                to = temp-1;
            }
        }
        return false;
    }
};