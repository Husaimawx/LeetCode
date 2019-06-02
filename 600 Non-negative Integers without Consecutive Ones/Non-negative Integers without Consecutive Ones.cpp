class Solution {
public:
    int findIntegers(int num) {
        vector<long> base{1,2};
        while(base[base.size()-1]<=1000000000) {
            base.push_back(base.back()+base[base.size()-2]);
        }
        
        vector<int> input;
        while(num != 0) {
            input.push_back(num%2);
            num/=2;
        }
        int res = 0;
        for(int i = input.size()-1;i>=0;i--) {
            if(input[i] == 1) {
                if(i == input.size()-1 || input[i+1] == 0)
                    res += base[i];
                else {
                    res += base[i];
                    return res;
                }
            }
        }
        return res+1;
    }
};