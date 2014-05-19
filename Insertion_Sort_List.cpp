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
    ListNode *insertionSortList(ListNode *head) {
        ListNode **cur = &head, **iter = NULL;
        while (*cur) {
            iter = &head;
            while ((*iter)->val < (*cur)->val && iter != cur)
                iter = &((*iter)->next);
            if (iter != cur) {
                ListNode *tmp = *iter;
                *iter = *cur;
                *cur = (*cur)->next;
                (*iter)->next = tmp;
            }
        }
        return head;
    }
};
