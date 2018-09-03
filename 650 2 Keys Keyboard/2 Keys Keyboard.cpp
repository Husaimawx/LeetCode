class Solution {
int min = 2;
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        int to = sqrt(n);
        for(int i = min;i<=to;i++)
        {
            if(n % i == 0)
            {
                min = i;
                return i+minSteps(n/i);
            }
        }
        return n;
    }
};