class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int temp = shifts[shifts.size()-1] % 26;
        vector<int> real(shifts.size(), temp);
        for(int i = int(shifts.size())-2;i>=0;i--) {
            real[i] = (real[i+1]+(shifts[i]%26))%26;
        }
        string ref = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
        for(int i = 0;i<S.size();i++) {
            int pos = ref.find(S[i]);
            S[i] = ref[pos+real[i]];
        }
        return S;
    }
};