class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),mid=0,ans=0;
        sort(nums.begin(),nums.end());
        mid=nums[n/2];
        for(int i=0;i<n;i++){
            ans+=(abs(nums[i]-mid));
        }
        return ans;
    }
};