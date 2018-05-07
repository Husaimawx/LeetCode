class Solution { 
public: 
    int maxPoints(vector<Point>& points) {
        map<pair<int,int>,int> slopes;
        
        int res = 0;
        int duplicate;
        int temp1,temp2,temp3;
        for(int i = 0;i<points.size();i++)
        {
            slopes.clear();
            duplicate = 1;
            for(int j = i+1;j<points.size();j++)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    duplicate++;
                else
                {
                    if(points[i].x == points[j].x)
                        slopes[make_pair(INT_MAX,INT_MAX)]++;
                    else
                    {
                        temp1 = points[j].x-points[i].x;
                        temp2 = points[j].y-points[i].y;
                        temp3 = gcd(temp1,temp2);
                        slopes[make_pair(temp1/temp3,temp2/temp3)]++;
                    }
                }
            }
            res = max(res,duplicate);
            for(auto slope:slopes)
            {
                if(slope.second+duplicate>res)
                    res = slope.second+duplicate;
            }
        }
        return res;
    }

private:
    int gcd(int num1, int num2)
    {
        int temp;
        while(num2)
        {
            temp = num2;
            num2 = num1%num2;
            num1 = temp;
        }
        return num1;
    }
};