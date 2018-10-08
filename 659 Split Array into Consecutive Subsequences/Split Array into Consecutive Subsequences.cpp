class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int from = nums[0];
        int to = nums[nums.size()-1];
        vector<int> count(to-from+1,0);
        for(int i = 0;i<nums.size();i++)
        {
            count[nums[i]-from]++;
        }
        int n1 = count[0];
        int n2 = 0;
        int n3 = 0;
        for(int i = 1;i<count.size();i++)
        {
            if(count[i] < (n1+n2))
                return false;
            int temp = max(0,count[i]-n1-n2-n3);
            n2 = n1;
            n1 = temp;
            n3 = max(0,count[i]-n1-n2);
        }
        if(n1 == 0 && n2 == 0)
            return true;
        return false;
    }
};

