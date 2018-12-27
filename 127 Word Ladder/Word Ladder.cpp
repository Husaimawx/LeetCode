class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag = -1;
        for(int i = 0;i<wordList.size();i++) {
            if(wordList[i] == endWord) {
                flag = i;
                break;
            }
        }
        
        if(flag == -1)
            return 0;
        if(beginWord == endWord)
            return 1;
        if(valid(beginWord,endWord))
            return 2;
        
        vector<int> temp;
        vector<vector<int>> data(wordList.size(),temp);
        
        for(int i = 0;i<wordList.size();i++) {
            for(int j = i+1;j<wordList.size();j++) {
                if(valid(wordList[i],wordList[j])) {
                    data[i].push_back(j);
                    data[j].push_back(i);
                }
            }
        }
        
        vector<int> num;
        map<int,int> M;
        int level = 2;
        for(int i = 0;i<wordList.size();i++) {
            if(valid(wordList[i],beginWord)) {
                num.push_back(i);
                M[i] = level;
            }
        }
        
        int from = 0;
        while(1) {
            level++;
            if(from == num.size())
                return 0;
            int size = num.size();
            for(int i = from;i<size;i++) {
                for(int j = 0;j<data[num[i]].size();j++) {
                    if(M.count(data[num[i]][j]) == 0) {
                        if(data[num[i]][j] == flag)
                            return level;
                        M[data[num[i]][j]] = level;
                        num.push_back(data[num[i]][j]);
                    }
                }
            }
            from = size;
        }
    }
    
    bool valid(string s1, string s2) {
        int time = 0;
        for(int i = 0;i<s1.size();i++) {
            if(s1[i] != s2[i])
                time += 1;
        }
        if(time != 1)
            return false;
        return true;
    }
};