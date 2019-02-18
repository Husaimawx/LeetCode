class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10)
            return num;
        string s = to_string(num);
        int i;
        for(i = 1;i<s.size();i++) {
            if(s[i-1]<s[i])
                break;
        }
        if(i == s.size())
            return num;
        
        int pos = s.size()-1;
        for(int j = s.size()-2;j>=i;j--) {
            if(s[pos] < s[j])
                pos = j;
        }
        for(int j = 0;;j++) {
            if(s[j] < s[pos]) {
                char temp = s[j];
                s[j] = s[pos];
                s[pos] = temp;
                return stoi(s);
            }
        }
        return 0;
    }
};