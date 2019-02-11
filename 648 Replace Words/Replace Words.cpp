class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> v;
        int from = 0;
        while(1) {
            int to = sentence.find(' ', from);
            if(to == -1) {
                v.push_back(sentence.substr(from, sentence.size()-from));
                break;
            } else {
                v.push_back(sentence.substr(from, to-from));
                from = to+1;
            }
        }
        
        auto comp = [](string& a, string& b) {
          return a.size() < b.size();  
        };
        
        sort(dict.begin(),dict.end(),comp);
        for(int i = 0;i<v.size();i++) {
            for(int j = 0;j<dict.size();j++) {
                if(isin(dict[j],v[i])) {
                    v[i] = dict[j];
                    break;
                }
            }
        }
        
        string res = "";
        for(int i = 0;i<v.size();i++) {
            res += v[i];
            if(i+1 != v.size())
                res += " ";
        }
        return res;
    }
    
    bool isin(string& a, string& b) {
        if(b.size() < a.size())
            return false;
        
        int i = 0;
        for(i = 0;i<a.size();i++) {
            if(a[i] != b[i])
                break;
        }
        if(i == a.size())
            return true;

        return false;
    }
};
