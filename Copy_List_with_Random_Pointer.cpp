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
        RandomListNode *newHead = new RandomListNode(head->label), **pOld = &head, **pNew = &newHead;
        unordered_map<int, RandomListNode*> table;
        table[head->label] = newHead;
        while ((*pOld)->next) {
            (*pNew)->next = new RandomListNode((*pOld)->next->label);
            table[(*pOld)->next->label] = (*pNew)->next;
            pOld = &((*pOld)->next);
            pNew = &((*pNew)->next);
        }
        pOld = &head;
        pNew = &newHead;
        while ((*pOld)) {
            if ((*pOld)->random)
                (*pNew)->random = table[(*pOld)->random->label];
            pOld = &((*pOld)->next);
            pNew = &((*pNew)->next);
        }
        return newHead;
    }
};
