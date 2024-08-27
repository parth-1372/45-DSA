class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Initialize the dp array with -1.
        vector<int> dp(n+1, -1);

        // Base case: If length is 0, no cuts can be made.
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            // If a cut of length x can be made
            if (i >= x && dp[i - x] != -1)
                dp[i] = max(dp[i], dp[i - x] + 1);

            // If a cut of length y can be made
            if (i >= y && dp[i - y] != -1)
                dp[i] = max(dp[i], dp[i - y] + 1);

            // If a cut of length z can be made
            if (i >= z && dp[i - z] != -1)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        // If dp[n] is still -1, it means no valid cuts were possible.
        return max(0, dp[n]);
    }
};