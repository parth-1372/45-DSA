class Solution {
public:
    // Function to find the middle of the list and split it
    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        tail->next = (left != nullptr) ? left : right;
        
        return dummy.next;
    }

    // Main merge sort function
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* middle = getMiddle(head);
        ListNode* nextOfMiddle = middle->next;
        
        middle->next = nullptr;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(nextOfMiddle);
        
        ListNode* sortedList = merge(left, right);
        
        return sortedList;
    }

    // Function to sort the list
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};