class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        int n = nums.size();
        
        // Populate the map with indices
        for (int i = 0; i < n; ++i) {
            map[nums[i]].push_back(i);
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int complement = k - num;

            if (num * 2 == k && map[num].size() >= 2) {
                // Handle case where num + num = k
                map[num].pop_back(); // Remove the current index
                map[num].pop_back(); // Remove another index
                ans++;
                // cout << i << " "; // Uncomment for debugging
            } else if (num != complement && map[complement].size() > 0) {
                // Handle case where num + complement = k
                if (map[num].size() > 0 && map[complement].size() > 0) {
                    map[num].pop_back(); // Remove the current index
                    map[complement].pop_back(); // Remove one index of complement
                    ans++;
                    // cout << i << " "; // Uncomment for debugging
                }
            }
        }

        return ans;
    }
};
