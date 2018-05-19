class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int from = 0, to = numbers.size()-1;
        while(1)
        {
            int temp = numbers[from]+numbers[to];
            if(temp == target)
            {
                vector<int> res(2,0);
                res[0] = from+1;
                res[1] = to+1;
                return res;
            }
            else if(temp < target)
            {
                from++;
            }
            else
            {
                to--;
            }
        }
    }
};