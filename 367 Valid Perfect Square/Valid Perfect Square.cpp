class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1)
            return true;
        int min = 1, max = 46340;
        if(max >= num)
            max = num;
        while(min <= max)
        {
            int mid = (min+max)/2;
            if(mid*mid == num)
                return true;
            else if(mid*mid < num)
                min = mid+1;
            else
                max = mid-1;
        }
        return false;
    }
};