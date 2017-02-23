// use dummy node to simplify the question that the first node can be deleted.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(head->val + 1), *pre{&dummy}, *cur{head};
        dummy.next = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int cur_val = cur->val;
                while (cur && cur->val == cur_val)
                    cur = cur->next;
                pre->next = cur;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
