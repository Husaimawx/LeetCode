class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = 0;
        int count = 0;
        while(len != senate.size()) {
            len = senate.size();
            string s;
            for(int i = 0;i<senate.size();i++) {
                if(senate[i] == 'R') {
                    if(count >= 0) {
                        s += 'R';
                    }
                    count++;
                } else {
                    if(count <= 0) {
                        s += 'S';
                    }
                    count--;
                }
            }
            swap(senate,s);
        }
        if(senate[0] == 'R')
            return "Radiant";
        else
            return "Dire";
    }
};