class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        int start = -1;
        string stack = s;
        for(int i = 0; i<len;i++)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    start++;
                    stack[start] = s[i];
                    break;
                case ')':
                    if(start == -1)
                        return false;
                    if(stack[start] == '(')
                        start--;
                    else
                        return false;
                    break;
                case ']':
                    if(start == -1)
                        return false;
                    if(stack[start] == '[')
                        start--;
                    else
                        return false;
                    break;
                case '}':
                    if(start == -1)
                        return false;
                    if(stack[start] == '{')
                        start--;
                    else
                        return false;
                    break;
                default:
                    return false;
            }
        }
        if(start == -1)
            return true;
        else
            return false;
    }
};