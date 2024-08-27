class Solution {
public:
    int knightDialer(int n) {
        vector<int> dp(10, 1);
        int mod = 1000000007;
        
        // Predefined possible moves for each digit
        vector<vector<int>> moves = {
            {4, 6},    // 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {3, 9, 0}, // 4
            {},        // 5 (no valid moves)
            {1, 7, 0}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
        };
        
        for (int i = 2; i <= n; i++) {
            vector<int> temp(10, 0);
            for (int j = 0; j < 10; j++) {
                for (int move : moves[j]) {
                    temp[j] = (temp[j] + dp[move]) % mod;
                }
            }
            dp = temp;
        }
        
        int ans = 0;
        for (int count : dp) {
            ans = (ans + count) % mod;
        }
        
        return ans;
    }
};
