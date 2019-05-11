class Solution {
public:
    unordered_map<int,int> count;
    unordered_map<int,vector<int>> next;
    int res = 0;
    int numSquarefulPerms(vector<int>& A) {
        for(int i = 0;i<A.size();i++) {
            count[A[i]] += 1;
        }
        vector<int> temp;
        for(auto iter = count.begin();iter != count.end();iter++) {
            next[iter->first] = temp;
        }
        for(auto it1 = count.begin();it1 != count.end();it1++) {
            for(auto it2 = it1;it2 != count.end();it2++) {
                int num1 = it1->first;
                int num2 = it2->first;
                int base = sqrt(num1+num2);
                if(base*base == num1+num2) {
                    next[num1].push_back(num2);
                    if(it1 != it2)
                        next[num2].push_back(num1);
                }
            }
        }
        for(auto iter:next) {
            cout << iter.first << " " << iter.second.size() << endl;
        }
        
        for(auto iter:count) {
            count[iter.first] -= 1;
            dfs(iter.first,int(A.size())-1);
            count[iter.first] += 1;
        }
        return res;
    }
    
    void dfs(int last, int remain) {
        if(remain == 0) {
            res += 1;
            return;
        }
        for(int i = 0;i<next[last].size();i++) {
            if(count[next[last][i]] != 0) {
                count[next[last][i]] -= 1;
                dfs(next[last][i],remain-1);
                count[next[last][i]] += 1;
            }
        }
        return;
    }
};