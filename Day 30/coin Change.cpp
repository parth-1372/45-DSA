class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        if(n==0)return 0;
        vector<int> dp(n+1,INT_MAX);
        for(int i=0;i<=n;i++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i==coins[j]){
                   mini=0;
                   break;
                }
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    mini=min(mini,dp[i-coins[j]]);
                }
            }
            if(mini!=INT_MAX)dp[i]=mini+1;
        }
        for(int i=0;i<=n;i++){
            if(dp[i]==INT_MAX)dp[i]=-1;
            cout<<dp[i]<<" ";
        }
       
        return dp[n];
    }
};