class Solution {
public:
    int f(int i, int curr0, int curr1, int n, int max0, int max1, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
        if (i == arr.size()) {
            return 0;  
        }
        
        if (dp[i][curr0][curr1] != -1) {
            return dp[i][curr0][curr1];
        }
        
        int ans = f(i + 1, curr0, curr1, n, max0, max1, arr, dp);
        
        if (curr0 + arr[i][0] <= max0 && curr1 + arr[i][1] <= max1) {
            ans = max(ans, 1 + f(i + 1, curr0 + arr[i][0], curr1 + arr[i][1], n, max0, max1, arr, dp));
        }
        
        return dp[i][curr0][curr1] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<int>> arr(l);
        for (int i = 0; i < l; i++) {
            int temp1 = 0, temp2 = 0;
            for (char c : strs[i]) {
                if (c == '1') temp2++;
                else temp1++;
            }
            arr[i] = {temp1, temp2};
        }
        
        vector<vector<vector<int>>> dp(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return f(0, 0, 0, l, m, n, arr, dp);
    }
};
