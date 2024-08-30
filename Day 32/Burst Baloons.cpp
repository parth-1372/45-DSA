class Solution {
public:
    int f(vector<int>& arr ,int i, int j,vector<vector<int>>& dp){
        if(i>j)return 0;
        int cost = INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++){
          cost = max(cost , arr[i-1]*arr[k]*arr[j+1] + f(arr,k+1,j,dp)+f(arr,i,k-1,dp));
        }
        return dp[i][j]=cost;
    }
    int maxCoins(vector<int>& nums) {
       int n = nums.size();
       vector<int> arr(n+2,1);
       for(int i=1;i<=n;i++)arr[i]=nums[i-1];
      vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
       return f(arr,1,n,dp);
    }
};