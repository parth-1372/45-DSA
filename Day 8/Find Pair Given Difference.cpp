class Solution {
public:
    int findPair(int n, int x, vector<int> &nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < n; ++i) {
            map[nums[i]]++;
        }
        
        for(int i = 0; i < n; ++i) {
            int requried1 = nums[i] - x; // Pair with value nums[i] - x
            int requried2 = nums[i] + x; // Pair with value nums[i] + x
            
            if(map.find(requried1) != map.end() && (requried1 != nums[i] || map[requried1] > 1)) {
                return 1; // Found a valid pair
            }
            
            if(map.find(requried2) != map.end() && (requried2 != nums[i] || map[requried2] > 1)) {
                return 1; // Found a valid pair
            }
        }
        
        return -1; // No valid pair found
    }
};
