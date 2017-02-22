// Solution 1 regular method based on Reverse Linked List I
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m == n) return head;
        
        ListNode *pre = NULL;
        ListNode *cur = head;
        
        for (int i = 0; i < m - 1; i++) {
            pre = cur;
            cur = cur->next;
        }
        
        ListNode *pl = pre;
        ListNode *pr = cur;
        
        for (int i = 0; i <= n - m; i++) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        pr->next = cur;
        if (pl == NULL) return pre;
        pl->next = pre;
        return head;
    }
};

// use three pointers
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return dummy.next;
    }
};

