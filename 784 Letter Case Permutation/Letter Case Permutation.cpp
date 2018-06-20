class Solution {
public:
    vector<string> res;
    string line;
    
public:
    vector<string> letterCasePermutation(string S) {
        line = "";
        if(S.size() == 0)
        {
            res.push_back("");
            return res;
        }
        
        for(int i = 0;i<S.size();i++)
        {
            if(S[i]>='A' && S[i]<='Z')
                S[i] = S[i]+32;
        }
        
        letterCasePermutationAux(S,0);
        return res;
    }
    
    void letterCasePermutationAux(string S, int start)
    {
        if(start == S.size())
        {
            res.push_back(line);
            return;
        }
        
        if(S[start]<'a' || S[start]>'z')
        {
            line += S[start];
            letterCasePermutationAux(S, start+1);
            line.erase(line.end()-1);
            return;
        }
        
        line += S[start];
        letterCasePermutationAux(S, start+1);
        line[line.size()-1]-=32;
        letterCasePermutationAux(S, start+1);
        line.erase(line.end()-1);
        
        return;
    }
};