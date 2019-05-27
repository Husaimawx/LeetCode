class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> large(4,INT_MAX);
        large[2] = INT_MIN;
        large[3] = INT_MIN;
        for(int i = 0;i<rectangles.size();i++) {
            large[0] = min(large[0],rectangles[i][0]);
            large[1] = min(large[1],rectangles[i][1]);
            large[2] = max(large[2],rectangles[i][2]);
            large[3] = max(large[3],rectangles[i][3]);
        }
        
        long area = long(large[2]-large[0])*long(large[3]-large[1]);
        for(int i = 0;i<rectangles.size();i++) {
            area -= long(rectangles[i][2]-rectangles[i][0])*long(rectangles[i][3]-rectangles[i][1]);
            if(area < 0)
                return false;
        }
        if(area != 0)
            return false;
        //cout << 1;
        map<pair<int,int>,int> M;
        M[pair<int,int>(large[0],large[1])]+=1;
        M[pair<int,int>(large[0],large[3])]+=1;
        M[pair<int,int>(large[2],large[1])]+=1;
        M[pair<int,int>(large[2],large[3])]+=1;
        
        for(int i = 0;i<rectangles.size();i++) {
            M[pair<int,int>(rectangles[i][0],rectangles[i][1])]+=1;
            M[pair<int,int>(rectangles[i][0],rectangles[i][3])]+=1;
            M[pair<int,int>(rectangles[i][2],rectangles[i][1])]+=1;
            M[pair<int,int>(rectangles[i][2],rectangles[i][3])]+=1;
        }
        
        for(auto iter = M.begin();iter != M.end();iter++) {
            if(iter->second % 2 == 1)
                return false;
        }
        
        return true;
    }
};