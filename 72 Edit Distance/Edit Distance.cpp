class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0 || len2 == 0)
            return(len1+len2);
        vector<int> temp(len2+1,-1);
        vector<vector<int>> res(len1+1,temp);
        subminDistance(word1, word2, res, 0, 0);
        return res[0][0];
    }
    
    void subminDistance(string& word1, string& word2, vector<vector<int> >& res, int xfrom, int yfrom)
    {
        if (res[xfrom][yfrom] != -1)
            return;

        if (xfrom == word1.length())
        {
            res[xfrom][yfrom] = word2.length() - yfrom;
            return;
        }
        if (yfrom == word2.length())
        {
            res[xfrom][yfrom] = word1.length() - xfrom;
            return;
        }

        if (word1[xfrom] == word2[yfrom])
        {
            subminDistance(word1, word2, res, xfrom + 1, yfrom + 1);
            res[xfrom][yfrom] = res[xfrom + 1][yfrom + 1];
        }
        else
        {
            subminDistance(word1, word2, res, xfrom + 1, yfrom + 1);
            int temp1 = res[xfrom + 1][yfrom + 1] + 1;
            subminDistance(word1, word2, res, xfrom, yfrom + 1);
            int temp2 = res[xfrom][yfrom + 1] + 1;
            int temp3 = xfrom;
            for (temp3++; word1[temp3] != word2[yfrom] && temp3 != word1.length(); temp3++);
            if (temp3 == word1.length())
            {
                subminDistance(word1, word2, res, temp3, yfrom + 1);
                temp3 = res[temp3][yfrom + 1] + temp3 - xfrom;
            }
            else
            {
                subminDistance(word1, word2, res, temp3 + 1, yfrom + 1);
                temp3 = res[temp3 + 1][yfrom + 1] + temp3 - xfrom;
            }
            //if (temp1 == -1 || temp2 == -1 || temp3 == -1)
            //	int a = 1;
            res[xfrom][yfrom] = min(min(temp1, temp2), temp3);
        }
        return;
    }
};