class Solution {
public:
    bool helper(TreeNode* root, long mini, long maxi) {
        if (root == nullptr) return true;

        // Check if the current node's value is within the allowed range
        if (root->val <= mini || root->val >= maxi) return false;

        // Recursively check the left and right subtrees
        bool left = helper(root->left, mini, root->val);
        bool right = helper(root->right, root->val, maxi);
        
        // Return true only if both subtrees are valid
        return left && right;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
