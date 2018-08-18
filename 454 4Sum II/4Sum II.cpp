// my solution: using map, actually is a red-black tree
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> sumA, sumB;
        int n = A.size();
        if(n == 0)
            return 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(sumA.count(A[i]+B[j]))
                    sumA[A[i]+B[j]]+=1;
                else
                    sumA[A[i]+B[j]] = 1;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(sumB.count(C[i]+D[j]))
                    sumB[C[i]+D[j]]+=1;
                else
                    sumB[C[i]+D[j]] = 1;
            }
        }
        
        vector<int> listA(sumA.size(),0),listB(sumB.size(),0);
        int i = 0;
        for(auto iter = sumA.begin();iter != sumA.end();iter++)
        {
            listA[i] = iter->first;
            i++;
        }
        i = 0;
        for(auto iter = sumB.begin();iter != sumB.end();iter++)
        {
            listB[i] = iter->first;
            i++;
        }
        
        int res = 0;
        int iA = 0, iB = sumB.size()-1;
        while(iA != listA.size() && iB >= 0)
        {
            if(listA[iA]+listB[iB] == 0)
            {
                res += sumA[listA[iA]]*sumB[listB[iB]];
                iA++;
                iB--;
            }
            else if(listA[iA]+listB[iB] < 0)
                iA++;
            else
                iB--;
        }
        return res;
    }
};

// other's solution, using unordered_map, actually is a hashmap, so it will be faster than mine
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>  abSum;
        for(auto a : A) {
            for(auto b : B) {
                ++abSum[a+b];
            }
        }
        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = abSum.find(0 - c - d);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};