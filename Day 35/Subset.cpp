class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>>& ans , vector<int>& curr , int i){
        int n = nums.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        f(nums,ans,curr,i+1);
        curr.push_back(nums[i]);
        f(nums,ans,curr,i+1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        f(nums,ans,curr,0);
        return ans;
    }
};