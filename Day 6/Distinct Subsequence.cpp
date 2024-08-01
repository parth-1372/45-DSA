class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
    
        // vector<vector<unsigned long long int>> dp(m + 1, vector<unsigned long long int>(n + 1, 0));

        // Base case: An empty string t is a subsequence of any string s
        // for (int j = 0; j <= n; j++) {
        //     dp[0][j] = 1;
        // }
        vector<unsigned long long int> dp(n+1,1);

        // Fill dp array
        for (int i = 1; i <= m; i++) {
            vector<unsigned long long int> curr(n+1,0);
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) {
                    // dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                    curr[j]=curr[j-1]+dp[j-1];
                } else {
                    // dp[i][j] = dp[i][j - 1];
                    curr[j]=curr[j-1];
                }
            }
            dp=curr;
        }

        // return dp[m][n];
        return dp[n];
    }
};
