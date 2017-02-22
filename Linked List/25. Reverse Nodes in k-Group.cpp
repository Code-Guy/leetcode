// must traverse twice
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *node = pre;
        int count = 0;
        while (node = node->next) count++;
        node = head;
        while (count >= k) {
            for (int i = 0; i < k - 1; i++) {
                ListNode *tmp = node->next;
                node->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = node;
            node = node->next;
            count -= k;
        }
        return dummy.next;
    }
};
