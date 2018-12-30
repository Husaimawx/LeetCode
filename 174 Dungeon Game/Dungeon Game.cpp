class Solution {
public:
    int calculate(int a, int b) {
        int res;
        if (a >= 0) {
            res = max(1, b-a);
        }
        else {
            res = b - a;
        }
        return res;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int size1 = dungeon.size();
        if (size1 == 0)
            return 1;
        int size2 = dungeon[0].size();
        if (size2 == 0)
            return 1;

        if (dungeon[size1 - 1][size2 - 1] >= 0)
            dungeon[size1 - 1][size2 - 1] = 1;
        else
            dungeon[size1 - 1][size2 - 1] = 1 - dungeon[size1 - 1][size2 - 1];
        for (int i = size2 - 2; i >= 0; i--) {
            dungeon[size1 - 1][i] = calculate(dungeon[size1 - 1][i], dungeon[size1 - 1][i + 1]);
        }

        for (int j = size1 - 2; j >= 0; j--) {
            for (int i = size2 - 1; i >= 0; i--) {
                int down = INT_MAX;
                int left = INT_MAX;
                if (i != size2 - 1) {
                    // left
                    left = calculate(dungeon[j][i], dungeon[j][i + 1]);
                }
                //down
                down = calculate(dungeon[j][i], dungeon[j + 1][i]);
                dungeon[j][i] = min(left, down);
            }
        }

        return dungeon[0][0];
    }
};