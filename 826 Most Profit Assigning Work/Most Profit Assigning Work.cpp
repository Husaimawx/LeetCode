class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> M;
        M[0] = 0;
        M[INT_MAX] = INT_MAX;
        for(int i = 0;i<difficulty.size();i++) {
            if(M.count(difficulty[i]) == 0) {
                M[difficulty[i]] = profit[i];
            } else {
                M[difficulty[i]] = max(M[difficulty[i]], profit[i]);
            }
        }
        vector<int> task;
        for(auto iter = M.begin();iter != M.end(); iter++) {
            if(iter == M.begin())
                task.push_back(iter->first);
            else {
                if(iter->second > M[task[task.size()-1]])
                    task.push_back(iter->first);
            }
        }
        
        task.push_back(INT_MAX);
        //for(int i = 0;i<task.size();i++)
        //    cout << task[i] << " " << M[task[i]] << endl;
        //return 0;
        sort(worker.begin(), worker.end());
        int from = 0;
        int res = 0;
        for(int i = 0;i<worker.size();i++) {
            int j;
            for(j = from;worker[i] >= task[j];j++);
            res += M[task[j-1]];
            from = j-1;
        }
        return res;
    }
};