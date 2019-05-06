class Solution {
    int total;
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ret;
        total = target.size();
        int from = 0;
        while(1) {
            int res = search(stamp, target, from);
            if(res < 0) {
                ret.resize(0);
                return ret;
            }
            ret.push_back(res);
            if(total == 0) {
                reverse(ret.begin(),ret.end());
                return ret;
            }
            else
                from = max(0,res-int(stamp.size())+1);
        }
    }
    
    int search(string& stamp, string& target, int from) {
        for(int i = from;i+stamp.size()<=target.size();i++) {
            int j;
            int flag = 0;
            for(j = 0;j<stamp.size();j++) {
                if(target[j+i] != '?')
                    flag = 1;
                if(stamp[j]!=target[j+i] && target[j+i]!='?')
                    break;
            }
            if(flag == 1 && j == stamp.size()) {
                for(int k = i;k<i+j;k++) {
                    if(target[k] != '?')
                        total -= 1;
                    target[k] = '?';
                }
                return i;
            }
        }
        return -1;
    }
};