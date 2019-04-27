class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> x;
        map<int,vector<pair<int,int>>> M;
        for(int i = 0;i<rectangles.size();i++) {
            vector<pair<int,int>> temp;
            M[rectangles[i][0]] = temp;
            M[rectangles[i][2]] = temp;
        }
        
        for(auto iter = M.begin();iter != M.end();iter++)
            x.push_back(iter->first);
        
        for(int i = 0;i<rectangles.size();i++) {
            int left = find(x, rectangles[i][0]);
            int right = find(x, rectangles[i][2]);
            for(int j = left;j<right;j++) {
                M[x[j]].push_back(pair<int,int>(rectangles[i][1],rectangles[i][3]));
            }
        }
        long res = 0;
        //for(int i = 0;i<x.size();i++) {
        //    cout << x[i] << " " << M[x[i]].first << " " << M[x[i]].second << endl;
        //}
        for(int i = 1;i<x.size();i++) {
            if(M[x[i-1]].size() == 0)
                continue;
            res = (res + long(x[i]-x[i-1])*cal(M[x[i-1]])) % long(1000000007);
            //res = (res + long(x[i]-x[i-1])*(long(M[x[i-1]].second)-long(M[x[i-1]].first))) % long(1000000007);
        }
        return res;
    }
    
    long cal(vector<pair<int,int>>& v) {
        sort(v.begin(),v.end());
        long res = v[0].second-v[0].first;
        int right = v[0].second;
        for(int i = 1;i<v.size();i++) {
            int temp = max(right, v[i].first);
            right = max(right, v[i].second);
            res += right-temp;
        }
        return res;
    }
    
    int find(vector<int>& x, int num) {
        int from = 0;
        int to = x.size()-1;
        while(1) {
            int mid = (from+to)/2;
            if(x[mid] == num)
                return mid;
            if(x[mid] < num)
                from = mid+1;
            else
                to = mid-1;
        }
    }
};