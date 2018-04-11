class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0)
            return "";
        if(numRows == 1)
            return s;
        
        string ans = s;
        int numloop = 2*numRows-2;
        int length = s.length();
        int from = 0;
        for(int i = 0; i < length; i+=numloop)
        {
            ans[from] = s[i];
            from++;
        }
        for(int j = 1; j < numRows-1; j++)
        {
            for(int i = j; i < length; i+=numloop)
            {
                ans[from] = s[i];
                from++;
                if(i+numloop-2*j<length)
                {
                    ans[from] = s[i+numloop-2*j];
                    from++;
                }
            }
        }
        for(int i = numRows-1; i < length; i+=numloop)
        {
            ans[from] = s[i];
            from++;
        }
        return ans;
    }
};