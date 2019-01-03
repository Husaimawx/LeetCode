class Solution {

public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.size() == 0)
            return res;
        int from = 0;
        vector<string> split;
        while(from < input.size()) {
            int to;
            for(to = from;to < input.size() ;to++) {
                if(input[to]<'0' || input[to]>'9')
                    break;
            }
            
            if(to == from) {
                split.push_back(input.substr(from,1));
                from++;
            } else {
                split.push_back(input.substr(from,to-from));
                from = to;    
            }
        }
        return diffWaysToComputeAux(split,0,split.size());
    }
    
    vector<int> diffWaysToComputeAux(vector<string>& input, int from, int to) {
        vector<int> res;
        if(to-from == 1) {
            res.push_back(stoi(input[from]));
            return res;
        }
        for(int i = from+1;i<to;i+=2) {
            vector<int> left = diffWaysToComputeAux(input, from,i);
            vector<int> right = diffWaysToComputeAux(input, i+1,to);
            if(input[i] == "+") {
                for(int j = 0;j<left.size();j++) {
                    for(int k = 0;k<right.size();k++) {
                        res.push_back(left[j]+right[k]);
                    }
                }
            } else if(input[i] == "-") {
                for(int j = 0;j<left.size();j++) {
                    for(int k = 0;k<right.size();k++) {
                        res.push_back(left[j]-right[k]);
                    }
                }
            } else {
                for(int j = 0;j<left.size();j++) {
                    for(int k = 0;k<right.size();k++) {
                        res.push_back(left[j]*right[k]);
                    }
                }
            }
        }
        return res;
    }
};