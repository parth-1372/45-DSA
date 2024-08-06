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
    void helper(ListNode* curr,ListNode* prev){
        if(curr->next==nullptr){
            curr->next=prev;
            ans=curr;
            return;
        }
        helper(curr->next,curr);
        curr->next=prev;
        return;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return nullptr;
        helper(head,nullptr);
        return ans;
    }
};