class Solution {
public:
    bool isHappy(int n) {
        int temp;
        vector<int> htable(150,0);
        while(1)
        {
            temp = 0;
            while(n>0)
            {
                temp += (n%10)*(n%10);
                n/=10;
            }
            if(temp == 1)
                return true;
            if(htable[temp] == 1)
                return false;
            else
                htable[temp] = 1;
            
            n = temp;
        }
    }
};