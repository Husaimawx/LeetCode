// my solution
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1)
            return true;
        if(num <=0)
            return false;
        
        while(num > 1)
        {
            if(num % 4 !=0)
                return false;
            else
                num = num >> 2;
        }
        return true;
    }
};

// other solution
bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}