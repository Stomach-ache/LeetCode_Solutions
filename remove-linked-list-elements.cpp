/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ptr = head;
        while (ptr != nullptr && ptr->val == val) ptr = ptr->next;
        if (ptr == nullptr) return ptr;

        head = ptr;
        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};
