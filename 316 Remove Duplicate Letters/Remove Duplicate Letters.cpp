class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() == 0)
            return "";
        map<char, int> M;
        int count = 0;
        for(int i = 0;i<s.size();i++) {
            if(M.count(s[i]) == 0) {
                M[s[i]] = 1;
                count++;
            }
        }
        vector<int> mask(26,0);
        string res = removeDuplicateLettersAux(s,0,mask,count);
        return res;
    }
    
    string removeDuplicateLettersAux(string& s, int from, vector<int>& mask, int count) {
        int count2 = 0;
        map<char, int> M;
        int i;
        for(i = s.size()-1;i>=from;i--) {
            if(mask[s[i]-'a'] == 0 && M.count(s[i]) == 0) {
                M[s[i]] = 1;
                count2++;              
                if(count2 == count)
                    break;
            }
        }
        int k = from;
        char temp = 'z'+1;
        for(int j = from;j<=i;j++) {
            if(mask[s[j]-'a'] != 0)
                continue;
            if(s[j] < temp) {
                temp = s[j];
                k = j;
            }
        }
        string remain = "";
        if(count != 1) {
            mask[temp-'a'] = 1;
            remain = removeDuplicateLettersAux(s, k+1, mask, count-1);
        }
        string here(1,temp);
        return here+remain;
    }
};