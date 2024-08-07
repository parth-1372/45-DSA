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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *beforeLeft = dummy;

        // Move beforeLeft to the node just before the left position
        for (int i = 1; i < left; ++i) {
            beforeLeft = beforeLeft->next;
        }

        // `leftNode` is the first node in the sublist to reverse
        ListNode* leftNode = beforeLeft->next;
        ListNode* rightNode = leftNode;
        ListNode* prev = nullptr;
        ListNode* curr = leftNode;

        // Reverse the sublist from left to right
        for (int i = left; i <= right; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed sublist back to the original list
        beforeLeft->next = prev;
        leftNode->next = curr;

        return dummy->next;
    }
};
