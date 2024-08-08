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
    pair<ListNode*, ListNode*> reversee(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return {head, head};
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* tail = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return {prev, tail};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // Calculate the length of the linked list
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        ListNode* nextHead = nullptr;
        ListNode* curr = head;
        ListNode* ans = new ListNode(0);  // Dummy node
        ListNode* Tail = ans;
        
        while (length >= k) {
            int currCount = 0;
            ListNode* start = curr;
            ListNode* end = curr;
            
            // Move to the kth node
            while (currCount < k - 1) {
                end = end->next;
                currCount++;
            }
            
            nextHead = end->next;
            end->next = nullptr;
            
            auto reversed = reversee(start);
            Tail->next = reversed.first;
            Tail = reversed.second;
            
            length -= k;
            curr = nextHead;
        }
        
        // Attach the remaining part of the list
        Tail->next = curr;
        
        return ans->next;
    }
};
