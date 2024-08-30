
class Solution {
public:
    int equalPartition(int N, int arr[]) {
        int totalSum = std::accumulate(arr, arr + N, 0);
        
        if (totalSum % 2 != 0) {
            return 0;
        }
        
        int target = totalSum / 2;
       vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < N; ++i) {
            for (int j = target; j >= arr[i]; --j) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        
        return dp[target] ? 1 : 0;
    }
};