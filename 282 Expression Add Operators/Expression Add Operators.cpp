class Solution {
public:
    vector<string> res;
    
public:
    vector<string> addOperators(string num, int target) {
        if(num.size() == 0)
            return res;

        vector<long> st(2,0);
        for(int i = 1;i<=num.size();i++) {
            if(num[0] == '0' && i == 2)
                break;
            string past(num.substr(0,i));        
            st[1] = stol(past);
            addOperatorsAux(num,target, i, past, st);
        }
        
        return res;
    }
    
    void addOperatorsAux(string& num, int target, int from, string& past, vector<long>& st) {
        if(from == num.size()) {
            if(st.size() == 2) {
                if(target == st[1])
                    res.push_back(past);
            } else {
                if(st[0] == 1) {
                    if(st[1]+st[2] == target)
                        res.push_back(past);
                } else if(st[0] == -1) {
                     if(st[1]-st[2] == target)
                        res.push_back(past);                   
                }
            }
            return;
        }
        
        for(int i = from;i<num.size();i++) {
            if(i != from && num[from] == '0')
                break;
            int number = stol(num.substr(from,i-from+1));
            
            // *
            int temp = st[st.size()-1];
            int temp2 = temp*number;
            st[st.size()-1] = temp2;
            string stemp = past + "*" + num.substr(from,i-from+1);
            addOperatorsAux(num, target, i+1,stemp, st);
            st[st.size()-1] = temp;
            
            // + - 
            if(st.size() > 2) {
                vector<long> oldst(st);
                if(st[0] > 0) {
                    st[1] = st[1]+st[2];
                } else {
                    st[1] = st[1]-st[2];
                }
                st[2] = number;
                st[0] = 1;
                stemp = past + "+" + num.substr(from,i-from+1);
                addOperatorsAux(num, target, i+1, stemp, st);
                st[0] = -1;
                stemp = past + "-" + num.substr(from,i-from+1);
                addOperatorsAux(num, target, i+1, stemp, st);               
                st = oldst;
            } else {
                vector<long> oldst(st);
                st.push_back(number);
                st[0] = 1;
                stemp = past + "+" + num.substr(from,i-from+1);
                addOperatorsAux(num, target, i+1, stemp, st);
                st[0] = -1;
                stemp = past + "-" + num.substr(from,i-from+1);
                addOperatorsAux(num, target, i+1, stemp, st);        
                st = oldst;
            }
        }
        
        return;
    }
};