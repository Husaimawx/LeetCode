class Solution {
vector<string> alpha{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string,int> M;
        for(auto item : words) {
            string temp = convert(item);
            M[temp] = 1;
        }
        return M.size();
    }
    
    string convert(string& word) {
        string res = "";
        for(int i = 0;i<word.size();i++) {
            res += alpha[word[i]-'a'];
        }
        return res;
    }
};