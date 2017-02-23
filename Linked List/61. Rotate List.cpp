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
        if (!head || k == 0) return head;
        
        int count = 0;
        ListNode *cur = head;
        ListNode *pre = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        k %= count;
        if (k == 0) return head;
        cur = head;
        for (int i = 0; i < k; i++) {
            cur = cur->next;
        }
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode *newHead = pre->next;
        pre->next = NULL;
        cur->next = head;
        return newHead;
    }
};
