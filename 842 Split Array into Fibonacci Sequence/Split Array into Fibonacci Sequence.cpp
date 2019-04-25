class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        
        for(int i = 0;i<S.size();i++) {
            //cout << S.substr(1,3) << endl;
            long cons_first = stol(S.substr(0,i+1));
            //cout << "first" + to_string(first) << endl;
            if(cons_first > long(INT_MAX))
                 break;
            for(int j = i+1;j<S.size()-1;j++) {
                long second = stol(S.substr(i+1,j-i));
                if(second > long(INT_MAX))
                    break;
                //cout << second << endl;
                long first = cons_first;
                string temp = to_string(first)+to_string(second);
                if(first == 123 && second == 456)
                    cout << "fuck" << endl;
                vector<int> res;
                res.push_back(int(first));
                res.push_back(int(second));
                while(1) {
                    long t = first;
                    first = second;
                    second += t;
                    if(second > long(INT_MAX))
                        break;
                    //cout << second << endl;
                    temp += to_string(second);
                    //cout << temp << endl;
                    res.push_back(second);
                    if(temp.size() > S.size())
                        break;
                    else if(temp.size() == S.size()) {
                        if(temp == S)
                            return res;
                        else
                            break;
                    }
                }
            }
        }
        vector<int> res;
        return res;
    }
};