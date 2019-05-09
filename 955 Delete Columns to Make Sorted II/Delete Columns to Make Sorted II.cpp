class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        vector<int> rec{0,A.size()};
        for(int i = 0;i<A[0].size();i++) {
            //for(int e = 0;e<rec.size();e++)
            //    cout << rec[e];
            //cout << endl;
            vector<int> temp;
            int flag = 0;
            for(int j = 0;j+1<rec.size();j++) {
                temp.push_back(rec[j]);
                for(int k = rec[j];k+1<rec[j+1];k++) {
                    if(A[k][i] > A[k+1][i]) {
                        res += 1;
                        flag = 1;
                        break;
                    } else if(A[k][i] < A[k+1][i]) {
                        temp.push_back(k+1);
                    }
                }
                if(flag == 1)
                    break;
            }
            temp.push_back(A.size());
            if(flag == 1)
                continue;
            rec = temp;
            if(rec.size() == A.size()+1)
                return res;
        }
        return res;
    }
};