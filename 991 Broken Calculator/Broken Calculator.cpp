class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(Y <= X)
            return X-Y;
        if(Y%2 == 1)
            return 2+brokenCalc(X,(Y+1)/2);
        else
            return 1+brokenCalc(X,Y/2);
    }
};