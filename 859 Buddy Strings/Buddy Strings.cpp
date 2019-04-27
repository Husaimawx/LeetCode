class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A.size() == 0)
            return false;
        vector<int> time;
        map<char,int> M;
        int flag = 0;
        for(int i = 0;i<A.size();i++) {
            if(A[i] != B[i])
                time.push_back(i);
            if(M.count(A[i]) == 0)
                M[A[i]] = 1;
            else
                flag = 1;
        }
        if(time.size() != 0 && time.size() != 2)
            return false;
        if(time.size() == 0)
            return flag;
        return (A[time[0]] == B[time[1]]) && (A[time[1]] == B[time[0]]);
    }
};