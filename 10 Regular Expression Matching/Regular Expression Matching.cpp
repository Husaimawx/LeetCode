class Solution {
public:
    map<int,bool> M;
    int size1;
public:
    bool isMatch(string s, string p) {
        
        size1 = s.size();
        return isMatchAux(s,p,0,0);
    }
    
    bool isMatchAux(string s, string p, int froms, int fromp) {
        int code = (size1+2)*fromp+froms;
        if(M.count(code) != 0)
            return M[code];
        
        if(p.size() == fromp) {
            if(s.size() == froms) {
                M[code] = true;
                return true;
            } else {
                M[code] = false;
                return false;                
            }
        } else if(p.size() > fromp+1 && p[fromp+1] == '*') {
            bool res = false;
            char temp = p[fromp];
            for(int i = froms;i<=s.size();i++) {
                if(isMatchAux(s,p,i,fromp+2)) {
                    res = true;
                    break;
                }
                if(temp != '.' && s[i] != temp)
                    break;
            }
            M[code] = res;
            return res;            
        } else {
            if(s.size() == froms) {
                M[code] = false;
                return false;
            } else {
                if(p[fromp] != '.' && p[fromp] != s[froms]) {
                    M[code] = false;
                    return false;  
                }
                bool res = isMatchAux(s,p,froms+1,fromp+1);
                M[code] = res;
                return res;                
            }           
        } 
    }
};