class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j;
        int length = cost.size();
        int now;
        
        for(i = 0;i<length;i+=j)
        {
            now = 0;
            for(j = 0;j<length;j++)
            {
                now += (gas[(i+j)%length]-cost[(i+j)%length]);
                if(now < 0)
                {
                    break;
                }
            }
            if(j == length)
                return i;
            j++;
        }
        return -1;
    }
};