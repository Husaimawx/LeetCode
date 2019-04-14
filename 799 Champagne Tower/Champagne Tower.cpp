class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> res;
        vector<double> temp(1, double(poured));
        res.push_back(temp);
        for(int i = 1;i<=query_row;i++) {
            vector<double> temp(i+1,0);
            for(int j = 0;j<i;j++) {
                temp[j] += ((max(1.0,res[res.size()-1][j])-1)/2);
                temp[j+1] += ((max(1.0,res[res.size()-1][j])-1)/2);
            }
            res.push_back(temp);
        }
        return min(res[res.size()-1][query_glass],1.0);
    }
};