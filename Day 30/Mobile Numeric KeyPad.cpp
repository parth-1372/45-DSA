class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<vector<long long >> arr = {
            {0,8},
            {1,2,4},
            {2,1,5,3},
            {3,2,6},
            {4,1,7,5},
            {5,2,4,6,8},
            {6,3,5,9},
            {7,4,8},
            {8,7,5,9,0},
            {9,8,6}
        };
        vector<long long > dp(10,1);
        for(long long  i=2;i<=n;i++){
            vector<long long > temp(10,0);
            for(long long  j=0;j<10;j++){
                for(long long  k=0;k<arr[j].size();k++){
                    temp[j]+=dp[arr[j][k]];
                }
            }
            dp=temp;
        }
        long long ans=0;
        for(long long  i=0;i<10;i++)ans+=dp[i];
        return ans;
    }
};