class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if(n == 0)
            return res;
        int num = 1;
        
        while(1) {
            res.push_back(num);
            if(num*10 <= n)
                num = num*10;
            else {
                num+=1;
                if(num % 10 == 0) {
                    while(num % 10 == 0)
                        num /=10;
                    if(num == 1)
                        return res;
                } else if(num > n) {
                    num += (10-num%10);
                    while(num % 10 == 0)
                        num /=10;
                    if(num == 1)
                        return res;
                }                   
            }
        }
    }
};