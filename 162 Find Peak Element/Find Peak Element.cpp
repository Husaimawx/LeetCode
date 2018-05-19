// my solution 做麻烦了。。。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int from = -1, to = nums.size();
        int temp;
        while(1)
        {
            temp = (from+to)/2;
            if(nums[temp]<nums[temp+1])
            {
                for(int i = temp+1;i<to;i++)
                {
                    if(i == nums.size()-1 || nums[i] > nums[i+1])
                        return i;
                }
                to = temp;                
            }
            else
            {
                for(int i = temp;i>from;i--)
                {
                    if(i == 0 || nums[i] > nums[i-1])
                        return i;
                }
                from = temp+1;
            }
        }
    }
};

// best solution
public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}