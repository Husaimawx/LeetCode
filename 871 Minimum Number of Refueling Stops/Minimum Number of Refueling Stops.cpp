class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size() == 0) {
            if(startFuel >= target)
                return 0;
            else
                return -1;
        }
        
        stations.push_back(vector<int>{target, 0});
        stations.insert(stations.begin(), vector<int>{0, startFuel});
        
        vector<vector<int>> res(stations.size(),vector<int>(stations.size(), -1));
        
        res[0][0] = 0;

        for(int i = 1;i<res.size();i++) {
            for(int j = i;j<res.size();j++) {
                int left = -1;
                int down = -1;
                if(res[i][j-1] != -1) {
                    left = max(-1, res[i][j-1]-stations[j][0]+stations[j-1][0]);
                }
                if(res[i-1][j-1] != -1) {
                    down = max(-1, res[i-1][j-1]+stations[j-1][1]-stations[j][0]+stations[j-1][0]);
                }
                if(max(left, down) == -1)
                    break;
                else
                    res[i][j] = max(left, down);
                //cout << i << " " << j << " " << res[i][j] << endl;
                if(j == res.size()-1)
                    return i-1;
            }
        }
        return -1;
    }
};