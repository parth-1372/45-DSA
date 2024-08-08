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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even=new ListNode(0),*evenTail=even;
        ListNode *odd=new ListNode(0),*oddTail=odd;
        int i=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(i%2==0){
              ListNode *add=new ListNode(temp->val);
              evenTail->next=add;
              evenTail=add;
            }else{
              ListNode *add=new ListNode(temp->val);
              oddTail->next=add;
              oddTail=add;
            }
            i++;
            temp=temp->next;
        }
        evenTail->next=odd->next;
        return even->next;
    }
};