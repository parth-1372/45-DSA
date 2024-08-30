#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int superEggDrop(int k, int n) {
      vector<vector<int>> dp(k + 1,vector<int>(n + 1, 0));

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1) {
                    dp[i][j] = j;
                } else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int low = 1, high = j, result = INT_MAX;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        int breakCase = dp[i - 1][mid - 1];
                        int notBreakCase = dp[i][j - mid];

                        if (breakCase > notBreakCase) {
                            high = mid - 1;
                            result = min(result, breakCase + 1);
                        } else {
                            low = mid + 1;
                            result = min(result, notBreakCase + 1);
                        }
                    }
                    dp[i][j] = result;
                }
            }
        }

        return dp[k][n];
    }
};
