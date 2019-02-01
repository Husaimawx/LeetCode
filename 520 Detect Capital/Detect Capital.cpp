class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0)
            return true;
        if('a' <= word[0] && word[0] <= 'z') {
            for(int i = 1;i<word.size();i++) {
                if('a' > word[i] || 'z'<word[i])
                    return false;
            }
            return true;
        }

        if(word.size() == 1)
            return true;
        
        if('a' <= word[1] && word[1] <= 'z') {
            for(int i = 2;i<word.size();i++) {
                if('a' > word[i] || 'z'<word[i])
                    return false;
            }
            return true;
        } else {
            for(int i = 2;i<word.size();i++) {
                if('a' <= word[i] && 'z'>=word[i])
                    return false;
            }
            return true;           
        }
    }
};