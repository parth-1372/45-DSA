class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next; // Move head to the next node
        }
        
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                if (prev == nullptr) {
                    head = curr->next; // Update head if the head node is removed
                } else {
                    prev->next = curr->next;
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
