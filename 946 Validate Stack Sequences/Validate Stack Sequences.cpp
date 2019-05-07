class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int from = 0;
        for(int i = 0;i<pushed.size();i++) {
            st.push(pushed[i]);
            while(from != popped.size() && st.size() != 0 && popped[from] == st.top()) {
                from += 1;
                st.pop();
            }
        }
        if(st.size() == 0)
            return true;
        return false;
    }
};