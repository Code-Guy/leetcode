// two pointers, p1 and p2. p1 moves n step first, if p1 points to null, the head is the deleting node; else moves p1 and p2 simultaneously 
until p1's next is null, then p2 points to the previous node of the deleting node, so let p2->next = p2->next->next, return head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        if (p1 == NULL) {
            ListNode *nextHead = head->next;
            delete head;
            return nextHead;
        }
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *deletedNode = p2->next; 
        p2->next = p2->next->next;
        delete deletedNode;
        
        return head;
    }
};
