class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int count = -1;
        for(int i = 0;i<wordList.size();i++) {
            if(wordList[i] == endWord)
                count = i;
        }
        if(count == -1)
            return res;
        vector<vector<int>> fig(wordList.size());
        map<int,string> M;
        for(int i = 0;i<wordList.size();i++) {
            M[i] = wordList[i];
            for(int j = 0;j<i;j++) {
                if(test(wordList[i],wordList[j])) {
                    fig[i].push_back(j);
                    fig[j].push_back(i);
                }
            }
        }
        
        vector<int> v;
        vector<int> prev;
        map<int,int> lv;
        for(int i = 0;i<wordList.size();i++) {
            if(test(beginWord, wordList[i])) {
                v.push_back(i);
                prev.push_back(INT_MIN);
                lv[i] = 1;
                if(i == count) {
                    vector<string> temp{beginWord, endWord};
                    res.push_back(temp);
                    return res;
                }
            }
        }
        
        //cout << 0 << endl;
        //for(int i = 0;i<v.size();i++) {
        //    cout << v[i] << ' ' << prev[i] << endl;
        //}
        /*
        for(int i = 0;i<fig.size();i++) {
            for(int j = 0;j<fig[i].size();j++) {
                cout << fig[i][j];
            }
            cout << endl;
        }*/
        
        int level = 2;
        int from = 0;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<fig[v[i]].size();j++) {
                    if(lv.count(fig[v[i]][j]) == 0) {
                        lv[fig[v[i]][j]] = level;
                    }
                    if(fig[v[i]][j] == count) {
                        vector<string> temp{endWord};
                        int t = i;
                        while(1) {
                            //cout << t << endl;;
                            temp.push_back(M[v[t]]);
                            t = prev[t];
                            if(t == INT_MIN)
                                break;
                        }
                        temp.push_back(beginWord);
                        reverse(temp.begin(),temp.end());
                        res.push_back(temp);
                        //for(int i = 0;i<temp.size();i++) {
                        //    cout << temp[i] << ' ';
                        //}
                        //cout << endl;
                        continue;
                    }
                    if(lv[fig[v[i]][j]] == level) {
                        v.push_back(fig[v[i]][j]);
                        prev.push_back(i);
                    }
                }
            }
            from = to;
            //cout << level << endl;
            //for(int i = 0;i<v.size();i++) {
            //    cout << v[i] << prev[i] << ' ';
            //}
            level += 1;
            //cout << endl;
            if(res.size() != 0)
                return res;
        }
        return res;
    }
    
    bool test(string& a, string& b) {
        int count = 0;
        for(int i = 0;i<a.size();i++) {
            if(a[i] != b[i]) {
                count ++;
                if(count > 1)
                    return false;
            }
        }
        return (count == 1);
    }
};