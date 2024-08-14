

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() || postorder.empty()) {
            return nullptr;
        }
        unordered_map<int, int> postorderIndex;
        for (int i = 0; i < postorder.size(); ++i) {
            postorderIndex[postorder[i]] = i;
        }
        return construct(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postorderIndex);
    }

private:
    TreeNode* construct(const vector<int>& preorder, int preStart, int preEnd,
                        const vector<int>& postorder, int postStart, int postEnd,
                        unordered_map<int, int>& postorderIndex) {
        if (preStart > preEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int leftRootVal = preorder[preStart + 1];
        int leftRootIndex = postorderIndex[leftRootVal];
        int leftSize = leftRootIndex - postStart + 1;

        root->left = construct(preorder, preStart + 1, preStart + leftSize,
                               postorder, postStart, leftRootIndex,
                               postorderIndex);
        root->right = construct(preorder, preStart + leftSize + 1, preEnd,
                                postorder, leftRootIndex + 1, postEnd - 1,
                                postorderIndex);
        return root;
    }
};
