class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        set<pair<int, int>, greater<pair<int, int>>> s;
        for (auto &it : map) {
            s.insert({it.second, it.first});
        }
        
        vector<int> ans;
        int i = 0;
        for (auto &it : s) {
            if (i >= k) break;
            ans.push_back(it.second); 
            i++;
        }
        
        return ans;
    }
};
