class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        int carry = b;
        while(carry != 0)
        {
            int newsum = sum ^ carry;
            carry = (sum & carry)<<1;
            sum = newsum;
        }
        return sum;
    }
};