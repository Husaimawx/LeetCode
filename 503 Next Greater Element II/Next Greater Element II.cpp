class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), INT_MAX);
        if (nums.size() == 0)
            return res;
        if (nums.size() == 1)
        {
            res[0] = -1;
            return res;
        }
        int flag = 0;

        vector<int> st;
        st.push_back(0);
        int i = 1;

        while (1)
        {

            while (st.size() > 0 && nums[st[st.size()-1]] < nums[i])
            {
                res[st[st.size() - 1]] = nums[i];
                st.pop_back();
            }

            if (res[i] == INT_MAX)
                st.push_back(i);

            i++;
            if (i == nums.size())
            {
                i = 0;
                flag++;
                if (flag == 2)
                {
                    for (int i = 0; i<res.size(); i++)
                        if (res[i] == INT_MAX)
                            res[i] = -1;
                    return res;
                }
            }
        }
    }
};