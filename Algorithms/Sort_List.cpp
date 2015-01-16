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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
			return head;
		ListNode **pMid = &head, *pFast = head, *left, *right;
		while (pFast && pFast->next) {
			pFast = pFast->next->next;
			pMid = &((*pMid)->next);
		}
		right = sortList(*pMid);
		*pMid = NULL;
		left = sortList(head);
		return merge(left, right);
    }

	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode *head = NULL, **p = &head;
		while (left && right) {
			if (left->val < right->val) {
				*p = left;
				left = left->next;
			}
			else {
				*p = right;
				right = right->next;
			}
			p = &((*p)->next);
		}
		*p = left ? left : right;
		return head;
	}
};
