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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head)
			return head;
        ListNode **insert = &head;
		int len = n - m + 1;
		while (--m)
			insert = &((*insert)->next);
		ListNode *cur = *insert, *next = NULL;
		while (--len){
			next = cur->next;
			cur->next = next->next;
			next->next = *insert;
			*insert = next;
		}
		return head;
    }
};
