class Solution {
public:
    int knightDialer(int N) {
        vector<long> num(10,1);
        for(int i = 1;i<N;i++) {
            vector<long> temp(10,0);
            temp[0] = num[4]+num[6];
            temp[1] = num[6]+num[8];
            temp[2] = num[7]+num[9];
            temp[3] = temp[1];
            temp[4] = num[0]+num[3]+num[9];
            temp[6] = temp[4];
            temp[7] = num[2]+num[6];
            temp[8] = num[1]+num[3];
            temp[9] = temp[7];
            for(int j = 0;j<=9;j++)
                num[j] = temp[j]%(1000000007);
        }
        
        long sum = 0;
        for(int i = 0;i<=9;i++)
            sum += num[i];
        return int(sum % 1000000007);
    }
};