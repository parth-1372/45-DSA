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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head,*ans= new ListNode(0),*ansTail=ans;
        while(temp!=nullptr){
           if(temp->val<x){
            ListNode* add=new ListNode(temp->val);
            ansTail->next=add;
            ansTail=add;
           }
           temp=temp->next;
        }
        temp=head;
         while(temp!=nullptr){
           if(temp->val>=x){
            ListNode* add=new ListNode(temp->val);
            ansTail->next=add;
            ansTail=add;
           }
           temp=temp->next;
        }
        return ans->next;
    }
};