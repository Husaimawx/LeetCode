class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x < 0 || y<0 || z<0)
            return false;
        if(z == 0)
            return true;
        if(z > x+y)
            return false;
        while(x!=0 && y!=0) {
            if(x>=y)
                x-=y;
            else
                y-=x;
        }
        
        if(x == 0 && y == 0)
            return (z==0);
        
        if(z%y == 0)
            return true;
        else
            return false;
    }
};