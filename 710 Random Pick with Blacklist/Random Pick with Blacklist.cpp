class Solution {
    int remain;
    unordered_map<int,int> rank;
public:
    Solution(int N, vector<int> blacklist) {
        unordered_map<int,int> M;
        for(int j = 0;j<blacklist.size();j++)
            M[blacklist[j]] = 1;
        remain = N-blacklist.size();
        int i = remain;
        for(int num : blacklist) {
            if(num < remain) {
                while(M.count(i) != 0)
                    i++;
                rank[num] = i;
                i++;
            }
        }
        for(auto iter = rank.begin();iter != rank.end();iter++)
            cout << iter->first << ' ' << iter->second << endl;
    }
    
    int pick() {
        int index = rand() % remain;
        if(rank.count(index) == 0)
            return index;
        return rank[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */