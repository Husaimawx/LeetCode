class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size(), INT_MAX);
        int pos = 0;
        
        while(1) {
            int next = S.find(C, pos);
            if(next != -1) {
                for(int i = pos;i<=next;i++) {
                    res[i] = min(res[i],next-i);
                }
                pos = next+1;
            } else 
                break;
        }

        pos = S.find(C, 0);
        while(1) {
            int next = S.find(C, pos+1);
            if(next != -1) {
                for(int i = pos;i<next;i++) {
                    res[i] = min(res[i],i-pos);
                }
                pos = next;
            } else {
                for(int i = pos;i<S.size();i++) {
                    res[i] = min(res[i],i-pos);
                }
                break;
            }
        }
        return res;
    }
};