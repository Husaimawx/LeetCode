// other people's code
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int m = (len-1) / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int mid = nums[m], odd = 1, even = len - 1 - !(len&1);
        for(int i = 0; i < len;){
            if(nums[i] > mid && (!(i&1) || i > odd)){ 
                // Process 2 kinds of larger elements: 1) the one in even postion; 2) the one beyond current odd cursor's range. 
                swap(nums[i], nums[odd]);
                odd += 2;
            }else if(nums[i] < mid && ((i&1) || i < even)){ // Process 2 kinds of smaller elements, similar logic with larger elements.
                swap(nums[i], nums[even]);
                even -= 2;
            }else
                i++;
        }
    }
};