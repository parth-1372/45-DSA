/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSumFromNode(TreeNode* node, long long sum) { // Change sum type to long long
        if (node == nullptr) return 0;
        
        // Check if the current node completes the path
        int count = (node->val == sum) ? 1 : 0;
        
        // Continue the path to the left and right subtrees
        count += pathSumFromNode(node->left, sum - node->val);
        count += pathSumFromNode(node->right, sum - node->val);
        
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        
        // Count paths starting from the current node, plus paths starting from the left and right children
        return pathSumFromNode(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
