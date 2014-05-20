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
        if (!head)
            return NULL;
        RandomListNode *pHead = new RandomListNode(head->label), *pNext = head->next, **cur = &pHead;
        if (head->random)
            pHead->random = new RandomListNode(head->random->label);
        while (pNext) {
            (*cur)->next = new RandomListNode(pNext->label);
            if (pNext->random)
                (*cur)->next->random = new RandomListNode(pNext->random->label);
            cur = &((*cur)->next);
            pNext = pNext->next;
        }
        return pHead;
    }
};
