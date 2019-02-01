class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if(machines.size() == 0)
            return 0;
        
        int sum = 0;
        for(int i = 0;i<machines.size();i++)
            sum += machines[i];
        if(sum % machines.size() != 0)
            return -1;
        
        int mean = sum/machines.size();
        
        vector<int> res(machines.size(),0);
        for(int i = 0;i<machines.size();i++) {
            if(i == 0)
                res[i] = machines[i]-mean;
            else
                res[i] = res[i-1]+machines[i]-mean;
        }
        
        int maxnum = 0;
        for(int i = 0;i<machines.size();i++) {
            int left,right;
            if(i == 0)
                left = 0;
            else
                left = -res[i-1];
            right = res[i];
            
            if(left < 0)
                left = 0;
            if(right < 0)
                right = 0;
            maxnum = max(maxnum, left+right);
        }
        return maxnum;
    }
};