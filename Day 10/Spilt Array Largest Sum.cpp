class Solution {
public:
    bool CanAllocate(vector<int>& nums, int n, int k, int mid) {
        int currSum = 0, currK = 1;
        for (int i = 0; i < n; i++) {
            if (currSum + nums[i] > mid) {
                currK++;
                currSum = nums[i];
                if (currK > k) return false;
            } else {
                currSum += nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int left = INT_MIN, right = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);
            right += nums[i];
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (CanAllocate(nums, n, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
