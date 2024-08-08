class Solution {
public:
    // Function which returns the root of the flattened linked list.
    Node *flatten(Node *root) {
        vector<int> arr;
        
        // Collect all the elements into the vector
        Node* temp = root;
        while (temp != nullptr) {
            arr.push_back(temp->data);
            Node* bottomTemp = temp->bottom;
            while (bottomTemp != nullptr) {
                arr.push_back(bottomTemp->data);
                bottomTemp = bottomTemp->bottom;
            }
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Create the flattened linked list using the bottom pointer
        Node *newRoot = new Node(arr[0]);
        Node *current = newRoot;

        for (int i = 1; i < arr.size(); ++i) {
            current->bottom = new Node(arr[i]);
            current = current->bottom;
        }

        return newRoot;
    }
};
