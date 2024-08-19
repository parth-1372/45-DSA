Node* constructTree(int n, int pre[], char preLN[]) {
    // Step 1: Create a stack to hold non-leaf nodes
    stack<Node*> st;

    // Step 2: Initialize the root node with the first element in the preorder array
    Node* root = new Node(pre[0]);
    st.push(root);

    // Step 3: Traverse the rest of the nodes and construct the tree
    for (int i = 1; i < n; i++) {
        Node* node = new Node(pre[i]);

        // Case 1: The node on top of the stack needs a left child
        if (st.top()->left == NULL) {
            st.top()->left = node;
        }
        // Case 2: The node on top of the stack already has a left child, so it needs a right child
        else if (st.top()->right == NULL) {
            st.top()->right = node;
            st.pop();  // After assigning the right child, pop the node from the stack
        }

        // If the current node is not a leaf, push it onto the stack
        if (preLN[i] == 'N') {
            st.push(node);
        }
    }

    // Step 4: Return the root of the constructed tree
    return root;
}