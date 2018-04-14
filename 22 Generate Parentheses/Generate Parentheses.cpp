class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0)
        {
            ans.push_back("");
            return ans;
        }

        for(int i = 0;i<n;i++)
        {
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n-1-i);
            for (auto it1 = left.begin(); it1 != left.end(); it1 ++)
            {
                for (auto it2 = right.begin(); it2 != right.end(); it2 ++)
                {
                    ans.push_back("(" + *it1 + ")" + *it2);
                }
            }
        }
        return ans;
    }
};