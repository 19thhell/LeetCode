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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head)
            return head;
        ListNode *p1 = head, *p2 = head;
        while (p2) {
            p2 = p2->next;
            if (!p2)
                return NULL;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) {
                p1 = head;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};
