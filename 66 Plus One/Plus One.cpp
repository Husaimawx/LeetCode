class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9)
        {
            digits[digits.size()-1]++;
            return digits;
        }
        int i;
        for(i = digits.size()-1;i>=0;i--)
        {
            if(digits[i] != 9)
                break;
            else
                digits[i] = 0;
        }
        
        if(i == -1)
        {
            digits[0] = 1;
            digits.push_back(0);
            return digits;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
};