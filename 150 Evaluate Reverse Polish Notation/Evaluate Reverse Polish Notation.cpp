class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int temp;
        for(int i = 0;i<tokens.size();i++)
        {
            if(tokens[i] == "+")
            {
                temp = s.top();
                s.pop();
                temp += s.top();
                s.pop();
                s.push(temp);
            }
            else if(tokens[i] == "-")
            {
                temp = -1*s.top();
                s.pop();
                temp += s.top();
                s.pop();
                s.push(temp);                
            }
            else if(tokens[i] == "*")
            {
                temp = s.top();
                s.pop();
                temp *= s.top();
                s.pop();
                s.push(temp);                
            }
            else if(tokens[i] == "/")
            {
                temp = s.top();
                s.pop();
                temp = s.top()/temp;
                s.pop();
                s.push(temp);                
            }
            else
            {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};