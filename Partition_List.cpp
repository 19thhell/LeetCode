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
    ListNode *partition(ListNode *head, int x) {
        ListNode **p = &head, **cur = &head, *tmp = NULL;
        while(*p) {
            if ((*p)->val < x) {
                if (p == cur) {
                    p = cur = &((*cur)->next);
                    continue;
                }
                tmp = *p;
                *p = (*p)->next;
                tmp->next = *cur;
                *cur = tmp;
                cur = &((*cur)->next);
            }
            else p = &((*p)->next);
        }
        return head;
    }
};
