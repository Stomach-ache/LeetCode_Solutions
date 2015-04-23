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
    ListNode* rotateRight(ListNode* head, int k) {
        // the length of the list is zero or one
        if (head == nullptr || head->next == nullptr) return head;
        // $len: holds the length of the list
        int len = 0;
        // $last: pointer to the last node
        ListNode *last = nullptr;
        ListNode *ptr  = head;
        while (ptr != nullptr) {
            ++len;
            last = ptr;
            ptr  = ptr->next;
        }
        if (k >= len) k %= len;
        if (k == 0) return head;

        int i = 1;
        ptr = head;
        while (i < len - k) {
            ++i;
            ptr = ptr->next;
        }
        last->next = head;
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};
