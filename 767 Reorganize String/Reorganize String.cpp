class Solution {
public:
    string reorganizeString(string S) {
        if(S.size() < 2)
            return S;
        vector<int> time(26,0);
        for(int i = 0;i<S.size();i++)
            time[S[i]-'a'] += 1;
        
        int maxtime = 0;
        int maxpos = 0;
        for(int i = 0;i<26;i++) {
            if(time[i] > maxtime) {
                maxtime = time[i];
                maxpos = i;
            }
        }
        if(maxtime*2-1 > S.size())
            return "";
        
        vector<int> pos(S.size(),0);
        if(S.size() % 2 == 0) {
            for(int i = 0;i<S.size();i++) {
                pos[i] = (2*i)%(S.size()-1);
            }                
            pos[S.size()-1] = S.size()-1;
        } else {
            for(int i = 0;i<S.size();i++) {
                pos[i] = (2*i)%S.size();
            }
        }
        
        int from = 0;
        for(int i = maxpos;i<maxpos+26;i++) {
            int al = i%26;
            for(int j = 0;j<time[al];j++) {
                S[pos[from]] = 'a'+al;
                from += 1;
            }
        }
        return S;
    }
};