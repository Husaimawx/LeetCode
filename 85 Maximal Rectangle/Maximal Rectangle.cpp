class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = 0;
        
        vector<int> height(n,0);
        for(int i = 0;i<n;i++)
            if(matrix[0][i] == '1')
                height[i] = 1;
        int temp = largestRectangleArea(height);
            if(result < temp)
                result = temp;       
        
        for(int i = 1;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            int temp = largestRectangleArea(height);
            if(result < temp)
                result = temp;
        }
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        
        vector<int> res(heights.size(),0);
        for(int i = 0;i<heights.size();i++)
        {
            res[i] -= heights[i];
        }
        
        stack<pair<int,int>> num;
        num.push(pair<int,int>(-1,-1));
        for(int i = 0;i<heights.size();i++)
        {
            while(num.top().first>=heights[i])
            {
                num.pop();
            }

            res[i] += (i-num.top().second)*heights[i];
            
            num.push(pair<int,int>(heights[i],i));
        }
        
        stack<pair<int,int>> num2;
        num2.push(pair<int,int>(-1,heights.size()));
        for(int i = heights.size()-1;i>=0;i--)
        {
            while(num2.top().first>=heights[i])
            {
                num2.pop();
            }

            res[i] += (num2.top().second-i)*heights[i];
            
            num2.push(pair<int,int>(heights[i],i));
        }
        
        int finalres = 0;
        for(int i = 0;i<res.size();i++)
        {
            if(finalres < res[i])
                finalres = res[i];
        }
        return finalres;
    }
};