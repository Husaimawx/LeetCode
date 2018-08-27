class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letter(26,0);
        for(int i = 0;i<s.size();i++)
            letter[s[i]-'a']+=1;
        for(int i = 0;i<t.size();i++)
            letter[t[i]-'a']-=1;
        for(int i = 0;i<26;i++)
            if(letter[i] != 0)
                return ('a'+i);
    }
};