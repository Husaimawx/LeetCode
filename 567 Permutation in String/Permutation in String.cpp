class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        if(s2.size() == 0)
            return true;
        
        vector<int> v1(26,0);
        for(int i = 0;i<s1.size();i++) {
            v1[s1[i]-'a'] += 1;
        }
        int sum = s1.size();
        
        int from = 0;
        for(int i = 0;i<s2.size();i++) {
            
            v1[s2[i]-'a'] -= 1;
            sum--;

            while(v1[s2[i]-'a'] < 0) {
                v1[s2[from]-'a'] += 1;
                from++;
                sum++;
            }

            if(sum == 0)
                return true;
        }
        return false;
    }
};