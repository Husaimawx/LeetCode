// Time Limit Exceed
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
            return false;
        return isInterleaveAux(s1,s2,s3);
    }
    
    bool isInterleaveAux(string s1, string s2, string s3){
        if(s1.size() == 0)
        {
            if(s2 == s3)
                return true;
            else
                return false;
        } 
        if(s2.size() == 0)
        {
            if(s1 == s3)
                return true;
            else
                return false;
        }
        if((s1[0] == s3[0]) && isInterleaveAux(s1.substr(1),s2,s3.substr(1)))
            return true;
        if((s2[0] == s3[0]) && isInterleaveAux(s1,s2.substr(1),s3.substr(1)))
            return true;
        return false;
    }
};

// Right Solution (DP)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> temp(s2.size()+1,true);
        vector<vector<bool>> res(s1.size()+1,temp);
        
        if(s1.size()+s2.size() != s3.size())
            return false;
        
        for(int i = 0;i<=s1.size();i++)
        {
            for(int j = 0;j<=s2.size();j++)
            {
                int pos = i+j;
                if(pos == 0)
                    continue;
                
                if(i!=0 && s1[i-1] == s3[pos-1] && res[i-1][j] == true)
                    res[i][j] = true;
                else if(j!=0 && s2[j-1] == s3[pos-1] && res[i][j-1] == true)
                    res[i][j] = true;
                else
                    res[i][j] = false;
            }
        }
        
        return res[s1.size()][s2.size()];
    }
};