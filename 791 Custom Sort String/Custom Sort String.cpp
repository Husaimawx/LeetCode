class Solution {
public:
    string customSortString(string S, string T) {
        map<char,int> M;
        for(int i = 0;i<S.size();i++) {
            M[S[i]] = 0;
        }
        
        string remain;
        for(int i = 0;i<T.size();i++) {
            if(M.count(T[i]) == 0)
                remain.append(1,T[i]);
            else
                M[T[i]] += 1;
        }
        
        for(int i = 0;i<S.size();i++) {
            remain.append(M[S[i]],S[i]);
        }
        return remain;
    }
};