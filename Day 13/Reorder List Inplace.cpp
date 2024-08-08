/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // Helper function to reorder the list
        reorderListHelper(head);
    }

private:
    ListNode* reorderListHelper(ListNode* head) {
        if (head->next == nullptr) return head; // Return the last node

        // Find the last node and the node before the last node
        ListNode* lastNode = head;
        ListNode* prevToLast = nullptr;
        while (lastNode->next != nullptr) {
            prevToLast = lastNode;
            lastNode = lastNode->next;
        }

        // Base case: If the list has only two nodes left, finish reordering
        if (head->next == lastNode) {
            head->next = lastNode;
            lastNode->next = nullptr;
            return nullptr;
        }

        // Place the last node after the head
        prevToLast->next = nullptr; // Remove the last node from its previous position
        ListNode* tempNext = head->next;
        head->next = lastNode;
        lastNode->next = tempNext;

        // Recursive call to reorder the rest of the list
        reorderListHelper(tempNext);

        return lastNode;
    }
};
