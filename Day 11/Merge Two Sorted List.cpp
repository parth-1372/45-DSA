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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans,*other;
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        if(list1->val >= list2->val){
            ans=list2;
            other=list1;
        }
        else{
            ans=list1;
            other=list2;
        }
        ListNode *ans1=ans,*prev=ans1;
        while(ans1!=nullptr && other!=nullptr){
            if(ans1->val==other->val){
                ListNode *add=new ListNode(ans1->val);
                ListNode* temp=ans1->next;
                prev=ans1;
                ans1->next=add;
                add->next=temp;
                ans1=add;
                other=other->next;
            }else if(ans1->val > other->val){
              ListNode *add=new ListNode(other->val);
              prev->next=add;
              add->next=ans1;
              prev=add;
              other=other->next;
            }else{
                prev=ans1;
                ans1=ans1->next;
            }
        }
        if(other!=nullptr){
            prev->next=other;
        }
        return ans;
    }
};