// Solution 1 use a dummy head, a node to traverse the linked list, and insert node->next after dummy head.
// ->p1->p2-> break first link, then second, finally reconstruct the second reversely.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *node = head;
        while (node->next) {
            ListNode *tmp = dummy.next;
            dummy.next = node->next;
            node->next = node->next->next;
            dummy.next->next = tmp;
        }
        
        return dummy.next;
    }
};

// Solution 2 use three points: pre cur next to traverse the linked list, and reverse the link step by step
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
