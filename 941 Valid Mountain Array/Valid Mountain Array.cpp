class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        if(A[0] >= A[1] || A[A.size()-1]>=A[A.size()-2])
            return false;
        int time = 0;
        for(int i = 0;i<A.size()-2;i++) {
            int temp = (A[i]-A[i+1])*(A[i+1]-A[i+2]);
            if(temp == 0)
                return false;
            if(temp < 0)
                time++;
        }
        return time == 1;
    }
};