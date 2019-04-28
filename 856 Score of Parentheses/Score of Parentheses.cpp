class Solution {
public:
    int scoreOfParentheses(string S) {
        // ( -1 ) -2
        stack<int> res;
        res.push(-1);
        res.push(0);
        for(int i = 1;i<S.size();i++) {
            if(S[i] == '(') {
                res.push(-1);
                res.push(0);
            } else {
                int add = 1;
                if(res.top() != 0)
                    add = res.top()*2;
                res.pop();
                res.pop();
                if(res.size() != 0) {
                    add += res.top();
                    res.pop();
                }
                res.push(add);
            }
        }
        return res.top();
    }
};