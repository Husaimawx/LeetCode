class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size())
            return false;
        string s1("");
        string s2("");
        
        vector<int> Ls;
        vector<int> Rs;
        vector<int> Le;
        vector<int> Re;     
        
        for(int i = 0;i<start.size();i++) {
            if(start[i] == 'L') {
                s1 += start[i];
                Ls.push_back(i);
            } else if(start[i] == 'R') {
                s1 += start[i];
                Rs.push_back(i);
            }
        }
        for(int i = 0;i<end.size();i++) {
            if(end[i] == 'L') {
                s2 += end[i];
                Le.push_back(i);
            } else if(end[i] == 'R') {
                s2 += end[i];
                Re.push_back(i);
            }
        }
        
        if(s1 != s2)
            return false;
        
        for(int i = 0;i<Ls.size();i++) {
            if(Ls[i] < Le[i])
                return false;
        }
        for(int i = 0;i<Rs.size();i++) {
            if(Rs[i] > Re[i])
                return false;
        }
        return true;
    }
};