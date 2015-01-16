//Solution 1: 2-level pointer
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode **cur = &head, *tmp = NULL;
        while (*cur && (*cur)->next) {
            tmp = (*cur)->next;
            (*cur)->next = tmp->next;
            tmp->next = *cur;
            *cur = tmp;
            cur = &((*cur)->next->next);
        }
        return head;
    }
};

//Solution 2:recursive
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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || !head->next)
            return head;
        ListNode *p = head->next;
        head->next = p->next;
        p->next = head;
        head = p;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};
