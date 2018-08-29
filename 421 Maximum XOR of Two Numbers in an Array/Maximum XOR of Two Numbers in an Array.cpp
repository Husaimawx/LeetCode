class Solution {
public:
    int partition(vector<int>& nums, int start, int to, int bitnum)
    {
        while (1)
        {
            while (start <= to && ((nums[start] >> bitnum) & 1) == 0)
                start++;
            while (start <= to && ((nums[to] >> bitnum) & 1) == 1)
                to--;
            if (start > to)
                return start - 1;
            else
            {
                int temp = nums[start];
                nums[start] = nums[to];
                nums[to] = temp;
                start++;
                to--;
            }
        }
    }

    int getRes(vector<int>& nums, int l1, int l2, int r1, int r2, int from)
    {
        if (from < 0)
            return 0;

        int mid1 = partition(nums, l1, l2, from);
        int mid2 = partition(nums, r1, r2, from);
        int result1 = 0;
        int result2 = 0;
        int flag = 0;
        if (mid1 >= l1 && mid2<r2)
        {
            flag = 1;
            result1 = getRes(nums, l1, mid1, mid2 + 1, r2, from - 1);
        }

        if (mid1 < l2 && mid2 >= r1)
        {
            flag = 1;
            result2 = getRes(nums, mid1 + 1, l2, r1, mid2, from - 1);
        }

        if (flag == 0)
            return getRes(nums, l1, l2, r1, r2, from - 1);

        return (1 << from) + max(result1, result2);
    }

    int findMaximumXOR(vector<int>& nums) {
        if (nums.size()<2)
            return 0;

        int max = 0;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] > max)
                max = nums[i];
        }
        int from = -1;
        while (max > 0)
        {
            max = max / 2;
            from++;
        }
        if (from == -1)
            return 0;

        int mid;
        while (1)
        {
            mid = partition(nums, 0, nums.size() - 1, from);
            if (mid >= 0 && mid != nums.size() - 1)
                break;
            else from--;
        }

        return (1 << from) + getRes(nums, 0, mid, mid + 1, nums.size() - 1, from - 1);
    }
};