class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        for(int i = 0;i<seats.size();i++) {
            if(seats[i] == 1)
                ones.push_back(i);
        }
        //cout << ones[0] << ones[1] << ones[2];
        int res = ones[0];
        res = max(res, int(seats.size())-1-ones[ones.size()-1]);
        //cout << res;
        for(int i = 1;i<ones.size();i++) {
            res = max(res,(ones[i]-ones[i-1])/2);
        }
        
        return res;
    }
};