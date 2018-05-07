class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right=x;
        while(left<right){
            int mid=left+(right-left)/2;
            if(x/mid>mid) left=mid+1;
            else if(x/mid<mid) right=mid;
            else if(x/mid==mid) return mid;
        }
        return right-1;
    }
};