class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int,int> M;
        for(int i : A) {
            if(M.count(i) == 0)
                M[i] = 1;
            else
                return i; 
        }
        return 0;
    }
};