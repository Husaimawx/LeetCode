class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q1;
        for(int i = 0;i<k;i++) {
            q1.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++) {
            q1.push(nums[i]);
            q1.pop();
        }
        return (q1.top());
    }
};