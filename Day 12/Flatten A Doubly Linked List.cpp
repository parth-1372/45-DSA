/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*, Node*> helper(Node* head) {
        if (head == nullptr) return {nullptr, nullptr};

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->child != nullptr) {
                Node* next = temp->next;
                auto child_pair = helper(temp->child);

                temp->next = child_pair.first;
                child_pair.first->prev = temp;

                if (next != nullptr) {
                    child_pair.second->next = next;
                    next->prev = child_pair.second;
                }

                temp->child = nullptr;
                temp = child_pair.second;
            }

            prev = temp;
            temp = temp->next;
        }

        return {head, prev};
    }

    Node* flatten(Node* head) {
        auto result = helper(head);
        return result.first;
    }
};