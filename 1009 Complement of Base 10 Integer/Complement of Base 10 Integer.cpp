class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0)
            return 1;
        if(N == 1)
            return 0;
        
        int time = int(log(N)/log(2)+1);
        return (1<<time)-N-1;
    }
};