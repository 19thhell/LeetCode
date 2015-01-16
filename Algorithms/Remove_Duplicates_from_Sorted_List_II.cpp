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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **p = &head, **next = &head;
        while (*p) {
            while ((*next)->next && (*next)->val == (*next)->next->val)
                next = &((*next)->next);
			if (next == p) {
				next = p = &((*p)->next);
				continue;
			}
			*p = (*next)->next;
			next = p;
        }
        return head;
    }
};
