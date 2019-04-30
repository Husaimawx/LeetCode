class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int from = 1;
        int to = 1;
        for(int i = 0;i<piles.size();i++) {
            to = max(to, piles[i]);
        }
        //cout << to << endl;
        while(from != to) {
            int mid = (from+to)/2;
            long h = compute(piles, mid);
            if(h <= long(H)) {
                to = mid;
            } else {
                from = mid+1;
            }
            //cout << from << to << endl;
        }
        
        return from;
    }
    
    long compute(vector<int>& piles, int N) {
        long res = 0;
        for(int i = 0;i<piles.size();i++) {
            res += (piles[i]+N-1)/N;
        }
        return res;
    }
};