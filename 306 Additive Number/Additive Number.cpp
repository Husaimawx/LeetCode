class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3)
            return false;
        for(int i = 1;i<=num.size()/2;i++) {
            for(int j = 1;j<=(num.size()-i)/2;j++) {
                if(num[0] == '0' && i != 1)
                    continue;
                if(num[i] == '0' && j != 1)
                    continue;
                if(isAdditiveNumberAux(num, i,j))
                    return true;
            }
        }
        return false;
    }
    
    bool isAdditiveNumberAux(string& num, int i, int j) {
        long num1 = stol(num.substr(0,i));
        long num2 = stol(num.substr(i,j));
        int k = i+j;
        //if(k >= num.size()) {
        //    return false
        //}
        while(1) {
            if(num[k] == 0)
                return false;
            long temp = num1+num2;
            long temp2 = temp;
            int pos = 0;
            while(temp2 != 0) {
                temp2/=10;
                pos++;
            }
            if(pos == 0)
                pos = 1;
            if(k+pos > num.size())
                return false;
            else {
                if(stol(num.substr(k,pos)) != temp)
                    return false;
                if(k+pos == num.size())
                    return true;
                else {
                    k += pos;
                    num1 = num2;
                    num2 = temp;
                }
            }
        }        
    }
};