class Solution {
public:
    int f(int curr , vector<pair<int,int>>& arr,vector<int>& dp){
        int n=arr.size();
        if(curr>=n)return 0;
        if(dp[curr]!=0)return dp[curr];
        int take=0,notTake=0;
        notTake=f(curr+1,arr,dp);
        if(curr==n-1){
            take=arr[curr].first*arr[curr].second;
        }else{
            if(arr[curr+1].first-1==arr[curr].first)take=arr[curr].first*arr[curr].second+f(curr+2,arr,dp);
            else take=arr[curr].first*arr[curr].second+f(curr+1,arr,dp);
        }
       return dp[curr]=max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> arr;
        int i=0;
        while(i<n){
            int count=0;
            int start=i;
            while(i<n && nums[i]==nums[start]){
                i++;
                count++;
            }
            arr.push_back({nums[start],count});
        }
        int l = arr.size();
        vector<int> dp(l,0);
        return f(0,arr,dp);
    }
};