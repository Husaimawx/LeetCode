class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        A = A + " " + B + " ";
        int from = 0;
        map<string, int> M;
        while(1) {
            int prev = from;
            from = A.find(" ", prev);
            //cout << from << endl;
            if(from == -1)
                break;
            string temp = A.substr(prev, from-prev);
            if(M.count(temp) == 0)
                M[temp] = 1;
            else
                M[temp] += 1;
            from += 1;
        }
        
        vector<string> res;
        for(auto iter = M.begin();iter != M.end();iter++) {
            if(iter->second == 1)
                res.push_back(iter->first);
        }
        return res;
    }
};