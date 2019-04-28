class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0;
        for(int i = 0;i<bills.size();i++) {
            if(!convert_able(five, ten, bills[i]))
                return false;
        }
        return true;
    }
    
    bool convert_able(int& five, int& ten, int bill) {
        if(bill == 5) {
            five += 1;
            return true;
        } else if(bill == 10) {
            if(five == 0)
                return false;
            else {
                five -= 1;
                ten += 1;
                return true;
            }
        } else {
            if(ten > 0 && five > 0) {
                ten -= 1;
                five -= 1;
                return true;
            }
            if(five > 2) {
                five -= 3;
                return true;
            }
            return false;
        }
    }
};