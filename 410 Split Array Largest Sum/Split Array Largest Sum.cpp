class Solution {
public:
    int getM(vector<int>& nums, int mid)
    {
        int res = 0;
        int sz = nums.size();
        int part = 0;
        for (int i = 0; i<sz; i++)
        {
            if (part + nums[i] <= mid)
            {
                part += nums[i];
            }
            else
            {
                part = nums[i];
                res += 1;
            }
        }
        return res+1;
    }

    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0)
            return 0;

        int sz = nums.size();
        int sum = 0;
        int max = 0;
        for (int i = 0; i<sz; i++)
        {
            if (nums[i] > max)
                max = nums[i];
            sum += nums[i];
        }

        if (m == 1)
            return sum;
        if (m == sz)
            return max;

        int from = max;
        int to = sum;
        while (from < to)
        {
            int mid = (from + to) / 2;
            int tempm = getM(nums, mid);
            if (tempm < m)
            {
                to = mid - 1;
            }
            else if(tempm > m)
            {
                from = mid+1;
            }
            else
            {
                to = mid;
            }
        }

        if(to < max)
            return max;
        return to;
    }
};