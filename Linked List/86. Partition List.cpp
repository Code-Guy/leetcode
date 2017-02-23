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
    ListNode* partition(ListNode* head, int x) {
        ListNode lhs(0), rhs(0);
        ListNode *lp = &lhs, *rp = &rhs;
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                lp->next = cur;
                lp = lp->next;
            }
            else {
                rp->next = cur;
                rp = rp->next;
            }
            cur = cur->next;
        }
        rp->next = NULL;
        lp->next = rhs.next;
        return lhs.next;
    }
};
