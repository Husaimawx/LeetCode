class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int answer = 0;
        int last = INT_MAX;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] != last)
            {
                last = nums[i];
                nums[answer] = last;
                answer++;
            }
        }
        return answer;
    }
};