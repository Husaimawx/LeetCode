class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old = image[sr][sc];
        if(old == newColor)
            return image;
        vector<int> index({1,0,-1,0,1});
        vector<pair<int,int>> bfs(1, pair<int,int>(sr,sc));
        image[sr][sc]  = newColor;
        
        int from = 0;
        while(from != bfs.size()) {
            int to = bfs.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<4;j++) {
                    int x = bfs[i].first+index[j];
                    int y = bfs[i].second+index[j+1];
                    if((x>=0) && (y>=0) && (x<image.size()) && (y<image[0].size()) && (image[x][y] == old)) {
                        image[x][y] = newColor;
                        bfs.push_back(pair<int,int>(x,y));
                    }
                }
            }
            from = to;
        }
        
        return image;
    }
};