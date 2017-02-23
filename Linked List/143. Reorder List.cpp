// 1.find the middle point 
// 2.reverse the second part 
// 3.interleave two parts together
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode *cur = p1->next;
        while (cur->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = p1->next;
            p1->next = tmp;
        }
        p2 = p1->next;
        p1->next = NULL;
        p1 = head;
        
        while (p2) {
            ListNode *next1 = p1->next;
            ListNode *next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};
