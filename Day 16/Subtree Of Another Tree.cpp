class Solution {
public:
    bool helper(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) return true;
        if (!root || !subroot) return false;
        if (root->val != subroot->val) return false;
        return helper(root->left, subroot->left) && helper(root->right, subroot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root) return !subroot;
        if (helper(root, subroot)) return true;
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};
