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
   pair<int,int> helper(ListNode* head){
    if(head->next==nullptr){
        if(head->val==0)return {0,1};
        return {1,1};
    }
    pair<int,int> ans = helper(head->next);
    ans.first=ans.first+head->val*pow(2,ans.second);
    ans.second++;
    return ans;
   }
    int getDecimalValue(ListNode* head) {
        auto ans=helper(head);
        return ans.first;
    }
};