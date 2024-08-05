class Solution {
public:
    int helper(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // Target is in the left sorted half
            if (target >= nums[left] && target < nums[mid]) {
                return helper(nums, target, left, mid - 1);
            } else {
                return helper(nums, target, mid + 1, right);
            }
        } else {
            // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                return helper(nums, target, mid + 1, right);
            } else {
                return helper(nums, target, left, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
};
