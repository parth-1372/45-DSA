class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& vis, vector<int>& nums, vector<int>& curr) {
        int n = nums.size();
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

            vis[i] = 1;
            curr.push_back(nums[i]);
            f(ans, vis, nums, curr);
            vis[i] = 0;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        vector<int> curr;
        f(ans, vis, nums, curr);
        return ans;
    }
};
