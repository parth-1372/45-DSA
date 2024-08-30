class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<int> next(n),prev(n);
        unordered_map<char,int> map,map2;
        for(int i=0;i<n;i++){
          if(map.find(s[i])==map.end())prev[i]=-1;
          else prev[i]=map[s[i]];
          map[s[i]]=i;
        }
        for(int i=n-1;i>=0;i--){
            if(map2.find(s[i])==map2.end())next[i]=n;
            else next[i]=map2[s[i]];
            map2[s[i]]=i;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int mod = 1000000007;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)dp[i][j]=1;
                else if(j-i==1)dp[i][j]=2;
                else{
                    if(s[i]!=s[j]){
                       dp[i][j]=((dp[i][j-1]+dp[i+1][j])%mod-dp[i+1][j-1])%mod;
                    }else{
                        int nxt = next[i];
                        int prv = prev[j];
                        if(nxt==j){
                            dp[i][j]=((2*dp[i+1][j-1])%mod+2)%mod;
                        }else if(nxt==prv){
                            dp[i][j]=((2*dp[i+1][j-1])%mod+1)%mod;
                        }else{
                            dp[i][j]=((2*dp[i+1][j-1])%mod-dp[nxt+1][prv-1])%mod;
                        }
                    }
                }
                if(dp[i][j]<0)dp[i][j]+=mod;
            }
        }
        
        return dp[0][n-1];
    }
};