// Solution 1 mine
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
        if (head == NULL) return NULL;
        
        ListNode *pre = head;
        ListNode *cur = head->next;
        
        while (cur) {
            if (cur->val != pre->val) {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
            else {
                pre->next = cur->next;
                cur = pre->next;
            }
        }
        return head;
    }
};

// Solution 2 concise two loops 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};

// Solution 3 concise one loop
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head, *tail = head;
        while (cur) {
            if(cur->val != tail->val){
                tail->next = cur;
                tail = cur;
            }
            cur = cur->next;
            tail->next = NULL;
        }
        return head;
    }
};

