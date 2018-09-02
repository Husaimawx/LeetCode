class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> num;
        for(int i = 0;i<timePoints.size();i++)
        {
            num.push_back(convert(timePoints[i]));
        }
        sort(num.begin(),num.end());
        int res = num[0]+24*60-num[num.size()-1];
        for(int i = 0;i<num.size()-1;i++)
        {
            if(num[i+1]-num[i] < res)
                res = num[i+1]-num[i];
        }
        return res;
    }
    
    int convert(string s)
    {
        int hour = stoi(s.substr(0,2));
        int minute = stoi(s.substr(3,2));
        return hour*60+minute;
    }
};