class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst)
            return 0;
        vector<pair<int, int>> temp;
        vector<vector<pair<int, int>>> dis(n, temp);
        for (int i = 0; i<flights.size(); i++)
        {
            dis[flights[i][0]].push_back(pair<int, int>(flights[i][1], flights[i][2]));
        }
        vector<vector<int>> table(K + 2, vector<int>(n, -1));
        table[0][src] = 0;
        for (int i = 0; i<(K + 1); i++)
        {
            for (int j = 0; j < n; j++)
                table[i + 1][j] = table[i][j];
            for (int j = 0; j<n; j++)
            {
                if (table[i][j] != -1)
                {
                    for (int t = 0; t<dis[j].size(); t++)
                    {
                        int tempdst = dis[j][t].first;
                        int tempdis = dis[j][t].second;
                        if (table[i + 1][tempdst] == -1 || table[i + 1][tempdst] > table[i][j] + tempdis)
                        {
                            table[i + 1][tempdst] = table[i][j] + tempdis;
                        }
                    }
                }
            }
        }

        return table[K + 1][dst];
    }
};