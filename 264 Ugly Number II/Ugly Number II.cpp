class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> inputs(3,0);
        inputs[0] = 2;
        inputs[1] = 3;
        inputs[2] = 5;
        return nthSuperUglyNumber(n, inputs);
    }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> answer(1,1);
        if(n == 1)
            return 1;
        
        vector<int> pointer(primes.size(), 0);
        while(answer.size() != n)
        {
            int min_index = 0;
            int min_value = INT_MAX;
            int temp;
            for(int j = 0; j<primes.size(); j++)
            {
                temp = primes[j]*answer[pointer[j]];
                if(temp == answer[answer.size()-1])
                {
                    pointer[j]++;
                    j--;
                    continue;
                }
                if(temp < min_value)
                {
                    min_value = temp;
                    min_index = j;
                }
            }
            answer.push_back(min_value);
            pointer[min_index] += 1;
        }
        
        return answer[n-1];
    }
};