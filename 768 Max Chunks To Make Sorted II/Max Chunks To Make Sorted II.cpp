class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() < 2)
            return arr.size();
        
        stack<int> st;
        st.push(arr[0]);
        
        for(int i = 1;i<arr.size();i++) {
            int tp = st.top();

            if(tp <= arr[i])
            {
                st.push(arr[i]);
                continue;
            }
            while(!st.empty() && st.top() > arr[i])
                st.pop();
            st.push(tp);
        }
        return st.size();
    }
};