class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        if (start >= end) return 0;
        
        int mid = start + (end - start) / 2;
        int leftCount = helper(nums, start, mid);
        int rightCount = helper(nums, mid + 1, end);
        
        int currCount = 0;
        int i = start, j = mid + 1;
        
        // Count reverse pairs
        while (i <= mid && j <= end) {
            if (nums[i] > 2LL * nums[j]) {
                currCount += (mid - i + 1);
                j++;
            } else {
                i++;
            }
        }
        
        // Merge step
        vector<int> temp;
        i = start;
        j = mid + 1;
        
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        
        while (j <= end) {
            temp.push_back(nums[j++]);
        }
        
        for (int k = start; k <= end; k++) {
            nums[k] = temp[k - start];
        }
        
        return leftCount + rightCount + currCount;
    }
    
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
