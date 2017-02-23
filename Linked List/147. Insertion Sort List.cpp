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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur) {
            while (pre->next && pre->next->val < cur->val)
                pre = pre->next;
            ListNode *next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = &dummy;
            cur = next;
        }
        return dummy.next;
    }
};
