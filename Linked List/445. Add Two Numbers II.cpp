// use two stacks
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int c = 0;
        ListNode *next = NULL;
        ListNode *cur = NULL;
        while (!s1.empty() || !s2.empty() || c != 0) {
            int d = c;
            if (!s1.empty()) {
                d += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                d += s2.top();
                s2.pop();
            }
            c = d / 10;
            d %= 10;
            cur = new ListNode(d);
            cur->next = next;
            next = cur;
        }
        return cur;
    }
};
