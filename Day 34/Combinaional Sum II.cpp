class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& arr, int index, vector<int>& currVec, int target, int sum) {
        if (sum == target) {
            ans.push_back(currVec);
            return;
        }
        if (index >= arr.size() || sum > target) return;

        for (int i = index; i < arr.size(); ++i) {
            if (i > index && arr[i] == arr[i - 1]) continue; 
            currVec.push_back(arr[i]);
            f(ans, arr, i + 1, currVec, target, sum + arr[i]);
            currVec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> currVec;
        f(ans, arr, 0, currVec, target, 0);
        return ans;
    }
};
