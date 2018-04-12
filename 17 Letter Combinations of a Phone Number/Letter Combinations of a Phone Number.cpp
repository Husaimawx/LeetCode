class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "")
            return ans;
        string predix = "";
        return subCombination(predix,digits);
    }
    
    vector<string> subCombination(string predix, string digits)
    {
        vector<string> ans;
        if(digits == "")
        {
            ans.push_back(predix);
            return ans;
        }
        else
        {
            string pos;
            switch(digits[0])
            {
                case '2':
                    pos = "abc";
                    break;
                case '3':
                    pos = "def";
                    break;
                case '4':
                    pos = "ghi";
                    break;
                case '5':
                    pos = "jkl";
                    break;
                case '6':
                    pos = "mno";
                    break;
                case '7':
                    pos = "pqrs";
                    break;
                case '8':
                    pos = "tuv";
                    break;
                case '9':
                    pos = "wxyz";
                    break;
            }
            for(int i = 0;i<pos.length();i++)
            {
                vector<string> branch;
                branch = subCombination(predix+pos[i],digits.substr(1, digits.length() - 1));
                ans.insert(ans.end(), branch.begin(), branch.end());
            }
            return ans;
        }
    }
};