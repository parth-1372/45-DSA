class Solution
{
    public:
    void inorder(Node* root, vector<int>& arr,int a) {
        if (root == nullptr) return;
        inorder(root->left, arr,a);
        if(root->key!=a)arr.push_back(root->key);
        inorder(root->right, arr,a);
    }

    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        vector<int> arr;
        inorder(root, arr,key);
        int n = arr.size();

        if (n == 0) { // No nodes in the tree
            pre = nullptr;
            suc = nullptr;
            return;
        }

        // Find predecessor and successor
        pre = nullptr;
        suc = nullptr;

        // If the key is smaller than the smallest element
        if (key < arr[0]) {
            suc = new Node(arr[0]);
            return;
        }

        // If the key is greater than the largest element
        if (key > arr[n - 1]) {
            pre = new Node(arr[n - 1]);
            return;
        }

        // Traverse the array to find predecessor and successor
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < key && arr[i + 1] > key) {
                pre = new Node(arr[i]);
                suc = new Node(arr[i + 1]);
                return;
            }
        }
    }
};