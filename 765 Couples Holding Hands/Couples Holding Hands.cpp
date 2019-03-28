class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        if(row.size() <=2){
            return 0;
        }
        
        vector<int> pos(row.size(),0);
        for(int i = 0;i<row.size();i++) {
            pos[row[i]] = i;
        }
        
        int count = 0;
        
        for(int i = 0;i<row.size();i+=2) {
            if(row[i]/2 == row[i+1]/2)
                continue;
            
            int neighbor = row[i];
            if(neighbor % 2 == 0)
                neighbor += 1;
            else
                neighbor -= 1;
            
            int people = pos[neighbor];
            row[people] = row[i+1];
            pos[row[i+1]] = people;
            
            count += 1;
        }
        
        return count;
    }
};