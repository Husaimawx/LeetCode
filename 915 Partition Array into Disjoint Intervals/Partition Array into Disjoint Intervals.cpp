class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> maxleft = A;
        for(int i = 1;i<A.size();i++) {
            maxleft[i] = max(maxleft[i-1],maxleft[i]);
        }
        vector<int> minright = A;
        for(int i = A.size()-2;i>=0;i--) {
            minright[i] = min(minright[i], minright[i+1]);
        }
        
        for(int i = 0;i<A.size()-1;i++) {
            if(maxleft[i] <= minright[i+1])
                return i+1;
        }
        return -1;
    }
};