class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s1 = matrix.size();
        if(s1 == 0)
            return false;
        int s2 = matrix[0].size();
        if(s2 == 0)
            return false;
        
        int i = 0,j = s2-1;
        while(1)
        {
            if(target == matrix[i][j])
                return true;
            else if(target < matrix[i][j])
            {
                j--;
                if(j < 0)
                    return false;
            }
            else
            {
               i++;
               if(i == s1)
                   return false;
            }
        }
    }
};