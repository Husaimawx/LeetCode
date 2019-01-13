class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> b(26,0);
        for(int i = 0;i<magazine.size();i++) {
            b[magazine[i]-'a']+=1;
        }
        for(int i = 0;i<ransomNote.size();i++) {
            b[ransomNote[i]-'a']-=1;
            if(b[ransomNote[i]-'a']<0)
                return false;
        }        
        return true;
    }
};