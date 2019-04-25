class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return ((sign(long(rec1[0])-long(rec2[2]))*sign(long(rec2[0])-long(rec1[2])))>0 && (sign(long(rec1[1])-long(rec2[3]))*sign(long(rec2[1])-long(rec1[3])))>0);
    }
    
    int sign(long a) {
        if(a == 0)
            return 0;
        return (a>0 ? 1:-1);
    }
};