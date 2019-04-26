class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0)
            return false;
        
        map<int,int> M;
        for(int i = 0;i<hand.size();i++) {
            if(M.count(hand[i]) == 0)
                M[hand[i]] = 1;
            else
                M[hand[i]] += 1;
        }
                
        //for(auto iter = M.begin();iter != M.end();iter++)
        //    cout << iter->first << " " << iter->second << endl; 
        
        while(M.size() != 0) {
            int s_value = M.begin()->first;
            int s_num = M.begin()->second;
            cout << s_value << " " << s_num << endl;
            for(int i = 0;i<W;i++) {
                if(M.count(s_value+i) == 0 || M[s_value+i] < s_num)
                    return false;
                M[s_value+i] -= s_num;
                if(M[s_value+i] == 0)
                    M.erase(s_value+i);
            }
        }
        return true;
    }
};