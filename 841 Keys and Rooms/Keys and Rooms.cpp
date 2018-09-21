class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size() == 0)
            return true;
        int n = rooms.size();
        vector<int> takeup(n,0);
        takeup[0] = 1;
        queue<int> q;
        q.push(0);
        
        while(q.size() != 0)
        {
            int temp = q.front();
            q.pop();
            for(int i = 0;i<rooms[temp].size();i++)
            {
                if(takeup[rooms[temp][i]] == 0)
                {
                    takeup[rooms[temp][i]] = 1;
                    q.push(rooms[temp][i]);
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(takeup[i] == 0)
                return false;
        }
        return true;
    }
};