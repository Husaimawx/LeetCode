class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.size() == 0)
            return -1;
        int time = B.size()/A.size();
        string temp = A + A;
        for(int i = 0;i<time;i++) {
            temp += A;
        }
        cout << temp;
        int pos = temp.find(B);
        cout << pos;
        if(pos == -1)
            return -1;
        else
            return (pos-1+B.size()+A.size())/A.size();
    }
};