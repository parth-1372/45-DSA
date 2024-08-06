class Solution {
public:
    pair<int, Node*> helper(Node* curr) {
        if (curr->next == nullptr) {
            // Last node in the list
            return {curr->data, curr};
        }
        
        auto prev = helper(curr->next);
        int maxInRight = max(prev.first, curr->data);
        
        // If the current node's value is less than maxInRight, it should be deleted
        if (curr->data < prev.first) {
            return {maxInRight, prev.second};
        } else {
            curr->next = prev.second;  // retain the current node
            return {maxInRight, curr};
        }
    }
    
    Node* compute(Node* head) {
        if (head == nullptr) return head;

        auto result = helper(head);
        return result.second;
    }
};
