class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        for(int i = 0;i<4;i++) {
            for(int j = 0;j<4;j++) {
                if(i == j)
                    continue;
                vector<double> line({nums[i]+nums[j], nums[i]-nums[j], nums[i]*nums[j], (double)(nums[i])/(double)(nums[j])});
                for(int k = 0;k<4;k++) {
                    int s = 0;
                    while(s == i || s == j)
                        s++;
                    vector<double> temp({nums[s],nums[6-i-j-s],line[k]});
                    if(judgePoint3(temp))
                        return true;
                }
            }
        }
        return false;        
    }
    
    bool judgePoint3(vector<double>& nums) {
        //if(nums[0] + nums[1] + nums[2] == 7.75)
        //    cout << "fuck";
        //cout << nums[0] << nums[1] << nums[2] << endl;
        for(int i = 0;i<3;i++) {
            for(int j = 0;j<3;j++) {
                if(i == j)
                    continue;
                vector<double> line({nums[i]+nums[j], nums[i]-nums[j], nums[i]*nums[j]});
                if(nums[j] != 0)
                    line.push_back(nums[i]/nums[j]);
                for(int k = 0;k<line.size();k++) {
                    vector<double> temp({nums[3-i-j],line[k]});
                    if(judgePoint2(temp))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool judgePoint2(vector<double>& nums) {
        if(nums[0] == 8 && nums[1] < 0.34 && nums[1] > 0.32)
            cout << nums[0] << nums[1] << endl;
        if(nums[0] + nums[1] == 24)
            return true;
        if(nums[0] - nums[1] == 24)
            return true;
        if(nums[1] - nums[0] == 24)
            return true;
        if(nums[0] * nums[1] == 24)
            return true;
        if(nums[0] != 0 && abs(nums[1] / nums[0] - 24) < 0.1)
            return true;
        if(nums[1] != 0 && abs(nums[0] / nums[1] - 24) < 0.1)
            return true;
        return false;
    }
};