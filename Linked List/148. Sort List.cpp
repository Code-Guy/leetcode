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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head), sortList(newHead));
    }
    
private:
    ListNode *mergeList(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        ListNode *merge = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                merge->next = left;
                left = left->next;
            }
            else {
                merge->next = right;
                right = right->next;
            }
            merge = merge->next;
        }
        merge->next = left ? left : right;
        return dummy.next;
    }
};
