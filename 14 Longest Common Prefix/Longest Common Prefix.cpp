class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if(num == 0)
            return "";
        //int* lengthList = new int(num);
        //for(int i = 0;i < num;i++)
        //{
        //    lengthList[i] = strs[i].length();
        //}
        for(int i = 0;i < strs[0].length();i++)
        {
            char c = strs[0][i];
            for(int j = 0;j < num;j++)
            {
                if(i >= strs[j].length() || c != strs[j][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};