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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        tail->next = head;
        ListNode *node = head;
        while (node && node->next) {
            tail->next = node->next;
            node->next = tail->next->next;
            tail->next->next = node;
            tail = node;
            node = node->next;
        }
        return dummy.next;
    }
};
