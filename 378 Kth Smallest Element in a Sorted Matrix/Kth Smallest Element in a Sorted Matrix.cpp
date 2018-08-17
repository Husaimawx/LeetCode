// priority_queue
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.emplace(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        int result = pq.top();
        return result;
    }
};

// binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 1)
            return matrix[0][0];
        
        int max = matrix[n-1][n-1];
        int min = matrix[0][0];
        while(min<max)
        {
            int mid = (max+min)/2;
            int result = find(matrix, mid);
            if(result == k)
                return find_value(matrix, mid);
            if(result < k)
                min = mid+1;
            else
            {
                max = mid;
            }
        }
        return min;
    }
    
    int find(vector<vector<int>>& matrix, int mid)
    {
        int res = 0;
        int i;
        for(i = 0;i<matrix.size();i++)
        {
            if(matrix[0][i] > mid)
                break;    
        }
        res+=i;
        for(int j = 1;j<matrix.size();j++)
        {
            while(i!=0)
            {
                if(matrix[j][i-1]>mid)
                    i--;
                else
                    break;
            }
            res+=i;
        }
        return res;
    }
    
    int find_value(vector<vector<int>>& matrix, int mid)
    {
        int res = 0;
        int i;
        for(i = 0;i<matrix.size();i++)
        {
            if(matrix[0][i] > mid)
                break;    
        }
        res = matrix[0][i-1];
        for(int j = 1;j<matrix.size();j++)
        {
            while(i!=0)
            {
                if(matrix[j][i-1]>mid)
                    i--;
                else
                    break;
            }
            if(i == 0)
                break;
            if(matrix[j][i-1] > res)
                res = matrix[j][i-1];
        }
        return res;        
    }
};