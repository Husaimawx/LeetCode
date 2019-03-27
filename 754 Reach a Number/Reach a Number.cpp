class Solution {
public:
    int reachNumber(int target) {
        long t = abs(target);
        long temp = 0;
        for(int i = 1;;i++) {
            temp += i;
            if(temp == t)
                return i;
            if(temp > t) {
                if((temp-t)%2 == 0)
                    return i;
            }
        }
    }
};