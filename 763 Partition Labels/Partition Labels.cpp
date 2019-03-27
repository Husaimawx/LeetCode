class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    
    vector<int> partitionLabels(string S) {
        vector<int> temp(2,-1);
        vector<vector<int>> pos(26, temp);
        for(int i = 0;i<S.size();i++) {
            if(pos[S[i]-'a'][0] == -1)
                pos[S[i]-'a'][0] = i;
            else
                pos[S[i]-'a'][1] = i;
        }
        vector<vector<int>> pos2;
        for(int i = 0;i<26;i++) {
            if(pos[i][1] != -1)
                pos2.push_back(pos[i]);
        }
        pos2.push_back(vector<int>({0,0}));
        pos2.push_back(vector<int>({S.size(),S.size()}));
        sort(pos2.begin(),pos2.end(), comp);
        for(int i = 0;i<pos2.size();i++) {
            cout << pos2[i][0] << pos2[i][1] << endl;
        }
        vector<int> res;
        for(int i = 1;i<pos2.size();i++) {
            if(pos2[i][0] > pos2[i-1][1]) {
                for(int j = pos2[i-1][1];j<pos2[i][0];j++)
                    res.push_back(j);
            }
            pos2[i][1] = max(pos2[i][1], pos2[i-1][1]);
        }
        for(int i = res.size()-1;i>=1;i--) 
            res[i] -= res[i-1];
        res[0] += 1;
        return res;
    }
};