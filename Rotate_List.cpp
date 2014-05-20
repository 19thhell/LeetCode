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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return NULL;
        ListNode **pHead = &head, **tail = &head, *tmp = NULL;
        while (k--) {
			while ((*tail)->next)
				tail = &((*tail)->next);
            tmp = *tail;
            *tail = (*tail)->next;
			tmp->next = *pHead;
			*pHead = tmp;
			tail = pHead;
        }
		return *pHead;
    }
};
