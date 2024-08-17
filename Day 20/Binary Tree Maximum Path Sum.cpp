class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxGain(root, ans);
        return ans;
    }

private:
    int maxGain(TreeNode* node, int& ans) {
        if (!node) return 0;

        int leftGain = max(0, maxGain(node->left, ans));
        int rightGain = max(0, maxGain(node->right, ans));

        int currentPathSum = node->val + leftGain + rightGain;

        ans = max(ans, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }
};
