// Solution 1 brute force method, based on merge two sorted linked lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while (true) {
            bool allEmpty = true;
            int minListIndex = 0;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    allEmpty = false;
                    if (lists[minListIndex] == NULL || 
                        lists[i]->val < lists[minListIndex]->val) minListIndex = i;
                }
            }
            if (allEmpty) break;
            
            tail->next = lists[minListIndex];
            tail = tail->next;
            lists[minListIndex] = lists[minListIndex]->next;
        }
        return dummy.next;
    }
};

// Solution 2 sub-call merge two sorted linked lists algorithm O(m^2n)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        while (lists.size() > 1) {
            ListNode *mergedList = mergeTwoLists(lists[lists.size() - 2], lists[lists.size() - 1]);
            lists.resize(lists.size() - 2);
            lists.push_back(mergedList);
        }
        return lists.front();
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Solution 3 use a heap O((mn)log(mn))
// priority_queue是一种抽象的数据结构，表征一种能以某种优先级in-out的数据结构，一般用heap(完全二叉树，父节点比子节点大)来实现。
   STL里的priority_queue使用make_heap push_heap pop_heap等基本操作。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct ListNodeComp {
        bool operator() (const ListNode *lhs, const ListNode *rhs) {
            return lhs->val > rhs->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, ListNodeComp> heap;
        for (ListNode *list : lists) {
            if (list) heap.push(list);
        }
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (!heap.empty()) {
            ListNode *minList = heap.top();
            heap.pop();
            tail->next = minList;
            tail = tail->next;
            if (minList->next) heap.push(minList->next);
        }
        return dummy.next;
    }
};
