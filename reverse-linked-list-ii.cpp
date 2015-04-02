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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // $pre_m points to the previous node of the mth node.
        // $pos_n points to the next node of the nth node.
        // $to_m  points to the mth node.
        // $to_n  points to the nth node.
        ListNode *pre_m = NULL, *pos_n = NULL, *to_m = head, *to_n = head;
        int i = 0;
        ListNode *p = head, *pre = NULL;
        while (p != NULL && i <= n) {
            i++;
            if (i == m - 1) pre_m = p;
            else if (i == m) to_m = p;
            // revese the range from mth node to nth node.
            if (i >= m && i <= n) {
                ListNode *temp = p->next;
                p->next = pre;
                if (i == n) {
                    to_n = p;
                    pos_n = temp;
                }
                pre = p;
                p = temp;
                continue;
            }
            pre = p;
            p = p->next;
        }

        if (m == 1) head = to_n;
        else pre_m->next = to_n;
        to_m->next = pos_n;

        return head;
    }
};
