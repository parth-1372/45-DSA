class Solution {
public:
    int f(int i, int pi, vector<int>& arr, vector<vector<int>>& dp) {
        int n = arr.size();
        if (i == n) {
            return 0;
        }
        if (dp[i][pi + 1] != -1) return dp[i][pi + 1];
        
         int first = f(i + 1, pi, arr, dp);
        
        int second = 0;
        if (pi == -1 || arr[i] > arr[pi]) {
            second = f(i + 1, i, arr, dp) + 1;
        }
        
        dp[i][pi + 1] = max(first, second);
        return dp[i][pi + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, memo);
    }
};
