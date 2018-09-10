class Solution {
public:
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