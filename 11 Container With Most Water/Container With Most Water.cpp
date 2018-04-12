class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxsize = 0;
        int size;
        int last = height.size()-1;
        int first = 0;
        while(first < last)
        {
            if(height[first] <= height[last])
            {
                size = height[first]*(last-first);
                if(size > maxsize)
                    maxsize = size;
                first++;
            }
            else
            {
                size = height[last]*(last-first);
                if(size > maxsize)
                    maxsize = size;
                last--;
            }
        }
        return maxsize;
    }
};