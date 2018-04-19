class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len == 1 || len == 0)
            return;
        int i,j;
        for(i = len-1;i>=1;i--)
        {
            if(nums[i] > nums[i-1])
                break;
        }
        
        int temp;
        int origin;
        if(i == 0)
        {
            for(i = 0;i<len/2;i++)
            {
                temp = nums[i];
                nums[i] = nums[len-1-i];
                nums[len-1-i] = temp;
            }
            return;
        }
        else
        {
            j = len-1;
            int mid;
            temp = nums[i-1];
            origin = i-1;
            while(i<j)
            {
                mid = (i+j+1)/2;
                if(nums[mid]<=temp)
                {
                    j = mid-1;
                }
                else
                {
                    i = mid;
                }
            }
            nums[origin] = nums[i];
            nums[i] = temp;
            i = origin+1;
            j = len-1;
            while(i<j)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            return;
        }
    }
};