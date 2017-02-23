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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) pre->next = cur->next;
            else pre = pre->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
