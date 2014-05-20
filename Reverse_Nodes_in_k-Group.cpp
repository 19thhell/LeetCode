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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k <= 1)
			return head;
		int i;
        ListNode **insert = &head;
		for (i = k;i >= 0;--i) {
			if (!(*insert))
				break;
            insert = &((*insert)->next);
		}
        if (i > 0)
            return head;
        insert = &head;
		ListNode *cur = *insert, *next = NULL;
		for (i = k - 1;i > 0;--i){
			next = cur->next;
			cur->next = next->next;
			next->next = *insert;
			*insert = next;
		}
		cur->next = reverseKGroup(cur->next, k);
		return head;
    }
};
