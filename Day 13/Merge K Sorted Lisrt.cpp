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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1 != nullptr) {
            temp->next = head1;
        } else {
            temp->next = head2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        if (k == 1) return lists[0];

        while (k > 1) {
            int j = 0;
            for (int i = 0; i < k; i += 2) {
                if (i + 1 < k) {
                    lists[j++] = merge(lists[i], lists[i + 1]);
                } else {
                    lists[j++] = lists[i];
                }
            }
            k = j;
        }

        return lists[0];
    }
};
