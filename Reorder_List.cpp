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
    void reorderList(ListNode *head) {
        if (!head || !head->next)
			return;
		ListNode **pMid = &head, *tmp = head;
		vector<ListNode *> partition(2);
		int len = 0;
		while (tmp && tmp->next) {
			tmp = tmp->next->next;
			pMid = &((*pMid)->next);
		}
		tmp = *pMid;
		while (tmp) {
			tmp = tmp->next;
			len++;
		}
		tmp = *pMid;
		*pMid = NULL;
		partition[0] = head;
		partition[1] = reverse(tmp, len);
		return merge(partition);
    }

	ListNode *reverse(ListNode *head, int len) {
		if (!head || !head->next)
			return head;
		ListNode **insert = &head, *cur = head, *next = NULL;
		while (--len) {
			next = cur->next;
			cur->next = next->next;
			next->next = *insert;
			*insert = next;
		}
		return head;
	}

	void merge(vector<ListNode *> p) {
		ListNode *head = NULL, **pHead = &head;
		int cur = 0;
		while (p[cur] && p[cur ^ 1]) {
			*pHead = p[cur];
			p[cur] = p[cur]->next;
			pHead = &((*pHead)->next);
			cur ^= 1;
		}
		*pHead = p[cur] ? p[cur] : p[cur ^ 1];
	}
};
