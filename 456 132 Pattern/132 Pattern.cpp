class Solution {
public:

    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        
        stack<int> st;
        st.push(INT_MAX);
        int s3 = INT_MIN;
        for(int i = nums.size()-2;i>=0;i--) {
            int s1 = nums[i];
            while(st.top()<nums[i+1]) {
                s3 = max(s3,st.top());
                st.pop();
            }
            st.push(nums[i+1]);
            if(i < nums.size()-2) {
                if(s1<s3)
                    return true;
            }
        }
        
        return false;
    }
};