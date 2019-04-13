class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<vector<int>> num;
        
        vector<int> temp;
        A.push_back(R+1);
        for(auto item : A) {
            if(item > R) {
                if(temp.size() != 0) {
                    num.push_back(temp);
                    temp.resize(0);
                }
            } else {
                temp.push_back(item);
            }
        }
        int res = 0;
        for(auto item : num) {
            res += (item.size()*(item.size()+1)/2);
            int count = 0;
            item.push_back(R);
            for(int i = 0;i<item.size();i++) {
                if(item[i] < L)
                    count += 1;
                else {
                    res -= (count+1)*count/2;
                    count = 0;
                }
            }
        }
        return res;
    }
};