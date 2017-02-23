// seperate odd and even lists, then append the even list to the odd list.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = p2;
        while (p2 && p2->next) {
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p3;
        return head;
    }
};
