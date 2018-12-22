class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        map<char, int> m1;
        for(int i = 0;i<s1.size();i++) {
            if(m1.count(s1[i]) == 0)
                m1[s1[i]] = 1;
            else
                m1[s1[i]] += 1;
        }
        for(int i = 0;i<s2.size();i++) {
            if(m1.count(s2[i]) == 0 || m1[s2[i]] == 0)
                return false;
            else
                m1[s2[i]] -= 1;            
        }
        
        if(s1.size() < 4)
            return true;
        
        for(int i = 1;i<s1.size();i++) {
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(i,s1.size()-i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s1.size()-i,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(0,s1.size()-i)))
                return true;
        }
        return false;
    }
};