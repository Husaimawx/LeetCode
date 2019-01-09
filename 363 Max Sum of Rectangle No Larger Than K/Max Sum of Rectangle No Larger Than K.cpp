class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return k;
        
        int res = INT_MIN;
        
        for(int i = 1;i<matrix[0].size();i++) {
            matrix[0][i] += matrix[0][i-1];
        }
        
        for(int j = 1;j<matrix.size();j++) {
            matrix[j][0] += matrix[j-1][0];
            for(int i = 1;i<matrix[0].size();i++) {
                matrix[j][i] += (matrix[j-1][i]+matrix[j][i-1]-matrix[j-1][i-1]);
            }
        }
        
        for (int j = 0; j<matrix.size(); j++) {
            for (int i = -1; i<j; i++) {
                vector<int> data;
                for (int k = 0; k<matrix[0].size(); k++) {
                    if(i >=0 )
                        data.push_back(matrix[j][k] - matrix[i][k]);
                    else
                        data.push_back(matrix[j][k]);
                }
                int temp = maxSumSubmatrixAux(data, k);
                if (temp > res)
                    res = temp;
            }
        }
        return res;
    }
    
    int maxSumSubmatrixAux(vector<int>& line, int k) {
        set<int> st{0};
        int res = INT_MIN;
        for(int i = 0;i<line.size();i++) {
            auto iter = st.lower_bound(line[i]-k);
            if(iter != st.end())
                res = max(res, line[i]-*iter);
            st.insert(line[i]);    
        }   
        return res;
    }
};