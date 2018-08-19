class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long int first = 0;
        long long int sum = 0,max = 0;
        long long int value = 0;
        for(int i = 0;i<A.size();i++)
        {
            first += i*A[i];
            sum += A[i];
        }
        for(int i = A.size()-1;i>0;i--)
        {
            value += (sum-A.size()*A[i]);
            if(value > max)
                max = value;
        }
        return (first+max);
    }
};