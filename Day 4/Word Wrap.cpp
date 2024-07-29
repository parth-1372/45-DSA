class Solution {
public:
    int solveWordWrap(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // DP array to store minimum cost
        vector<vector<int>> cost(n, vector<int>(n, 0)); // Cost matrix
        
        // Calculate cost of putting words from i to j in one line
        for (int i = 0; i < n; ++i) {
            int length = -1;
            for (int j = i; j < n; ++j) {
                length += (nums[j] + 1);
                if (length <= k) {
                    cost[i][j] = (j == n - 1) ? 0 : pow(k - length, 2); // No cost for last line
                } else {
                    cost[i][j] = INT_MAX; // Not possible to fit words i to j in one line
                }
            }
        }

        // Fill the DP array using the cost matrix
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (cost[i][j] != INT_MAX) {
                    if (j == n - 1) {
                        dp[i] = min(dp[i], cost[i][j]);
                    } else if (dp[j + 1] != INT_MAX) {
                        dp[i] = min(dp[i], cost[i][j] + dp[j + 1]);
                    }
                }
            }
        }

        return dp[0];
    }
};
