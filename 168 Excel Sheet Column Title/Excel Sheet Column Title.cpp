class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0)
            return "";
        
        n--;
        long long num = 26;
        int size = 1;
        while(n>=num)
        {
            n-=num;
            num*=26;
            size++;
        }
        
        string res(size,'A');
        for(int i = size-1;i>=0;i--)
        {
            res[i] += n%26;
            n/=26;
        }
        return res;
    }
};