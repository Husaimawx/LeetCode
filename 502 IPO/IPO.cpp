class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int,int>> projects;
        for(int i = 0;i<Profits.size();i++) {
            projects.push_back(pair<int,int>(Profits[i],Capital[i]));
        }
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return ((a.second < b.second) || (a.second == b.second && a.first > b.first));
        };
        
        sort(projects.begin(),projects.end(),comp);
        
        int time = 0;
        int to = 0;
        priority_queue<int> pq;
        while(time != k) {
            int from = to;
            while(to != projects.size() && projects[to].second <= W)
                to++;
            for(int i = from;i<to;i++) {
                pq.push(projects[i].first);
            }
            if(pq.size() == 0)
                return W;
            W += pq.top();
            cout << W;
            pq.pop();
            time+=1;
        }
        return W;
    }
};