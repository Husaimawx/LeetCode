class Solution {
public:
    int candy(vector<int>& ratings) {
        return candyAux(ratings, 0);
    }
    
    int candyAux(vector<int>& ratings, int from) {
        if(from >= ratings.size())
            return 0;
        if(from+1 == ratings.size())
            return 1;
        int i;
        int vertex = -1;
        for(i = from;i<ratings.size();i++) {
            if(i+1 == ratings.size()) {
                if(vertex == -1) {
                    int base = i-from+1;
                    return (base+1)*base/2;
                } else {
                    int base1 = vertex-from+1;
                    int base2 = i-vertex+1;
                    if(base1 < base2) {
                        swap(base1,base2);
                    }
                    base2 -=1;
                    return (base1+1)*base1/2+(base2+1)*base2/2;
                }
            } else if(vertex == -1) {
                if(ratings[i] == ratings[i+1]) {
                    return candyAux(ratings, i+1)+(i-from+1)*(i-from+2)/2;
                } else if(ratings[i] > ratings[i+1]) {
                    vertex = i;
                }
            } else {
                if(ratings[i] == ratings[i+1]) {
                    int base1 = vertex-from+1;
                    int base2 = i-vertex+1;
                    if(base1 < base2) {
                        swap(base1,base2);
                    }
                    base2 -=1;
                    return candyAux(ratings, i+1)+(base1+1)*base1/2+(base2+1)*base2/2;
                } else if(ratings[i] < ratings[i+1]) {
                    int base1 = vertex-from+1;
                    int base2 = i-vertex+1;
                    if(base1 < base2) {
                        swap(base1,base2);
                    }
                    base2 -=1;
                    return candyAux(ratings, i)+(base1+1)*base1/2+(base2+1)*base2/2-1;
                }                
            }
        }
    }
};