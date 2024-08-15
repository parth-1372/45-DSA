/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, TreeNode*> helper(TreeNode* root) {
        if (root == nullptr) return {nullptr, nullptr};

        pair<TreeNode*, TreeNode*> first = helper(root->left);
        pair<TreeNode*, TreeNode*> second = helper(root->right);

        TreeNode *head, *tail;
        root->left = nullptr;

        if (first.first == nullptr && second.first == nullptr) {
            head = root;
            tail = root;
        } else if (first.first != nullptr && second.first == nullptr) {
            root->right = first.first;
            head = root;
            tail = first.second;
        } else if (first.first == nullptr && second.first != nullptr) {
            root->right = second.first;
            head = root;
            tail = second.second;
        } else {
            root->right = first.first;
            first.second->right = second.first;
            head = root;
            tail = second.second;
        }

        return {head, tail};
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
};
