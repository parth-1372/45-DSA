
class Solution {
public:
    int total_cost(vector<vector<int>>& cost) {
        int n = cost.size();
        int VISITED_ALL = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));

        function<int(int, int)> tsp = [&](int mask, int pos) {
            if (mask == VISITED_ALL) {
                return cost[pos][0];  // Return to the starting point
            }
            if (dp[pos][mask] != INT_MAX) {
                return dp[pos][mask];  // Use the stored result
            }

            for (int city = 0; city < n; city++) {
                if ((mask & (1 << city)) == 0) {  // If city is not visited
                    int newCost = cost[pos][city] + tsp(mask | (1 << city), city);
                    dp[pos][mask] = min(dp[pos][mask], newCost);
                }
            }
            return dp[pos][mask];
        };

        return tsp(1, 0);  // Start the tour from the first city
    }
};