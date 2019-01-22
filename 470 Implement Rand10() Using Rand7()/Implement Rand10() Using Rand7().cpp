// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num1;
        while(1) {
            int temp = rand7();
            if(temp == 7)
                continue;
            if(temp % 2 == 0)
                num1 = 0;
            else
                num1 = 5;
            break;
        }
        while(1) {
            int temp = rand7();
            if(temp < 6)
                return (num1+temp); 
        }
    }
};