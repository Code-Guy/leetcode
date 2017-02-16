/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        clone(head);
        link(head);
        return detach(head);
    }
    
private:
    void clone(RandomListNode *head) {
        RandomListNode *oldNode = head;
        while (oldNode) {
            RandomListNode *newNode = new RandomListNode(oldNode->label);
            newNode->next = oldNode->next;
            oldNode->next = newNode;
            oldNode = newNode->next;
        }
    }
    
    void link(RandomListNode *head) {
        RandomListNode *oldNode = head;
        while (oldNode) {
            RandomListNode *newNode = oldNode->next;
            if (oldNode->random) // 注意随机指针可能为空
                newNode->random = oldNode->random->next;
            oldNode = newNode->next;
        }
    }
    
    RandomListNode *detach(RandomListNode *head) {
        RandomListNode *oldNode = head;
        RandomListNode *newHead = NULL;
        RandomListNode *newNode = NULL;
        
        if (oldNode) {
            newHead = newNode = oldNode->next;
            oldNode->next = newNode->next;
            oldNode = oldNode->next;
        }
        while (oldNode) {
            newNode->next = oldNode->next;
            newNode = newNode->next;
            oldNode->next = newNode->next;
            oldNode = oldNode->next;
        }
        return newHead;
    }
};
