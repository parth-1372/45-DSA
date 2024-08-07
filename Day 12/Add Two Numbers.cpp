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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=nullptr,*temp1=l1,*temp2=l2,*ansTail=nullptr;
        int carry=0;
        while(temp1!=nullptr && temp2!=nullptr){
            int sum = temp1->val+temp2->val+carry;
            carry=sum/10;
            int digit=sum%10;
            ListNode *add=new ListNode(digit);
            if(ans==nullptr){
                ans=add;
                ansTail=add;
            }else{
                ansTail->next=add;
                ansTail=ansTail->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            int sum = temp1->val+carry;
            carry=sum/10;
            int digit=sum%10;
            ListNode *add=new ListNode(digit);
            if(ans==nullptr){
                ans=add;
                ansTail=add;
            }else{
                ansTail->next=add;
                ansTail=ansTail->next;
            }
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            int sum = temp2->val+carry;
            carry=sum/10;
            int digit=sum%10;
            ListNode *add=new ListNode(digit);
            if(ans==nullptr){
                ans=add;
                ansTail=add;
            }else{
                ansTail->next=add;
                ansTail=ansTail->next;
            }
            temp2=temp2->next;
        }
        if(carry){
            ListNode* add=new ListNode(carry);
            ansTail->next=add;
        }
        return ans;
    }
};