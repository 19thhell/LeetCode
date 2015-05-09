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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **p = &head;
        while (*p) {
            while ((*p)->val == val) {
                *p = (*p)->next;
                if (*p == NULL)
                    return head;
            }
            p = &((*p)->next);
        }
        return head;
    }
};
