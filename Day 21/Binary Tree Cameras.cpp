class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) {
            cameras++;
        }
        return cameras;
    }

private:
    // Returns:
    // 0 -> node needs a camera
    // 1 -> node is covered by a camera
    // 2 -> node has a camera
    int dfs(TreeNode* node, int& cameras) {
        if (node == nullptr) return 1;

        int left = dfs(node->left, cameras);
        int right = dfs(node->right, cameras);

        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }

        if (left == 2 || right == 2) {
            return 1;
        }

        return 0;
    }
};
