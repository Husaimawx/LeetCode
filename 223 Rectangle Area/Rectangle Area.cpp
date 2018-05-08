class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {        
        return (D - B) * (C - A) + (H - F) * (G - E) - max(min(min(C - A, G - E),min(C - E, G - A)),0) * max(min(min(H - F, D - B),min(H - B, D - F)),0);
    }
};