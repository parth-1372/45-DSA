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
    ListNode* ans;

    void helper(ListNode* curr, ListNode* prev) {
        if (curr->next == nullptr) {
            curr->next = prev;
            ans = curr;
            return;
        }
        helper(curr->next, curr);
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        helper(head, nullptr);
        return ans;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode *slow = head, *fast = head;
        
        // Finding the middle of the list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        ListNode* reversed = reverseList(slow->next);
        ListNode* temp = head;

        // Compare the first half and the reversed second half
        while (reversed != nullptr) {
            if (temp->val != reversed->val) return false;
            temp = temp->next;
            reversed = reversed->next;
        }
        
        return true;
    }
};
