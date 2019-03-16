class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        k -= 1;
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums[nums.size()-1]-nums[0];
        
        while(low < high) {
            int mid = (low+high+1)/2;
            int left = choice(nums, mid);
            if(left <= k) {
                low = mid;
            } else {
                high = mid-1;
            }
        }
        
        return low;
    }
    
    int choice(vector<int>& nums, int diff) {
        int to = 1;
        int res = 0;
        for(int from = 0;from < nums.size();from++) {
            while(to < nums.size() && nums[to]-nums[from] < diff) {
                to++;
            }
            res += (to-from-1);
        }
        return res;
    }
};