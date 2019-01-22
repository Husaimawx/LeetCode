class Solution {
public:
    map<pair<int, int>, bool> M;
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*maxChoosableInteger+maxChoosableInteger < desiredTotal)
            return false;
        if(maxChoosableInteger < 2)
            return true;
        vector<bool> temp(maxChoosableInteger,true);
        return canIWinAux(temp,desiredTotal);
    }
    
    bool canIWinAux(vector<bool>& has,int target) {
        if(M.count(pair<int, int>(convertfrom(has),target)) == 1)
            return M[pair<int, int>(convertfrom(has),target)];
        int i;
        for(i = has.size()-1;i>=0;i--)
            if(has[i] == true)
                break;
        if(target <= i+1)
            return true;
        for(int i = 0;i<has.size();i++) {
            if(has[i] == true) {
                has[i] = false;
                if(canIWinAux(has,target-i-1) == false) {
                    has[i] = true;
                    M[pair<int, int>(convertfrom(has),target)] = true;
                    return true;
                }
                has[i] = true;
            }
        }
        M[pair<int, int>(convertfrom(has),target)] = false;
        return false;
    }
    
    int convertfrom(vector<bool>& B) {
        int res = 0;
        for(int i = 0;i<B.size();i++) {
            res = (res<<1)+B[i];
        }
        return res;
    }
    
};