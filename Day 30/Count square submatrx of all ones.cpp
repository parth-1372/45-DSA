class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(matrix[i][j] == 1) {
                    if(i == m-1 || j == n-1) {
                        dp[i][j] = 1;  
                    } else {
                        dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) + 1;
                    }
                    ans += dp[i][j];  
                }
            }
        }
        
        return ans;
    }
};
