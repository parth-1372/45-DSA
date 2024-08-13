class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or root is one of p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recur for left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right recursive calls returned non-null values,
        // it means p and q are located in different subtrees.
        if (left && right) {
            return root;
        }
        
        // If only one of the subtrees contains p or q, return that subtree's result.
        return left ? left : right;
    }
};
