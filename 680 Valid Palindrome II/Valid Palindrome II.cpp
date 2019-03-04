class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() < 3)
            return true;
        
        int from = 0;
        int to = s.size()-1;
        while(from < to) {
            if(s[from] == s[to])
            {
                from += 1;
                to -= 1;
            } else {
                if(check(s, from+1, to))
                    return true;
                if(check(s, from, to-1))
                    return true;
                return false;
            }
        }
        return true;
    }
    
    bool check(string& s, int from, int to) {
        while(from < to) {
            if(s[from] != s[to])
                return false;
            else
            {
                from += 1;
                to -= 1;
            }
        }
        return true;
    }
};