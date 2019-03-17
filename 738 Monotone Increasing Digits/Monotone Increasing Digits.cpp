class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int oldN = N;
        if(N < 10)
            return N;
        vector<int> digit;
        while(N != 0) {
            digit.push_back(N%10);
            N /= 10;
        }
        reverse(digit.begin(),digit.end());
        int i;
        int to = digit.size()-1;
        for(i = 0;i<to;i++) {
            if(digit[i] > digit[i+1])
                break;
        }
        if(i == to)
            return oldN;
        digit[i] -= 1;
        int j;
        for(j = i-1;j>=0;j--) {
            if(digit[j] > digit[j+1])
                digit[j] -=1;
            else
                break;
        }
        j+=1;
        int res = 0;
        for(int k = 0;k<=j;k++) {
            res = res*10+digit[k];
        }
        res += 1;
        for(int k = 0;k<digit.size()-1-j;k++) {
            res *= 10;
        }
        res -=1;
        return res;
    }
};