class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        if(right < 2)
            return 0;
        int lm = height[left],rm = height[right];
        while(left+1 < right)
        {
            if(lm < rm)
            {
                left++;
                if(lm >= height[left])
                {
                    res += (lm-height[left]);
                }
                else
                {
                    lm = height[left];
                }
            }
            else
            {
                right--;
                if(rm >= height[right])
                {
                    res += (rm-height[right]);
                }
                else
                {
                    rm = height[right];
                }                
            }
        }
        return res;
    }
};