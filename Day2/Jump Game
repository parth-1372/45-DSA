class Solution {
public:
   int helper(vector<int>& nums,int curr,vector<pair<int,int>>& p){
       if(curr>=nums.size()) return 0;
        int maxJump=nums[curr];
        if(maxJump+curr>=nums.size()-1)return 1;
        if(p[curr].first==1)return p[curr].second;
        p[curr].first=1;
        for(int i=1;i<=maxJump;i++){
            if(p[curr+i].first==0) {
               p[curr+i].second =  helper(nums,curr+i,p);
                if(p[curr+i].second)return 1;
            }
        }
       return 0;
    }
    bool canJump(vector<int>& nums) {
        vector<pair<int,int>> p(nums.size(),{0,0});
        int ans = helper(nums,0,p);
        if(ans)return true;
        return false;    
    }
};