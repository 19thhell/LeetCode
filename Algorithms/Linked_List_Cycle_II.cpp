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
        ListNode *pSlow = head;
        ListNode *pFast = head;
        while (pFast) {
            pFast = pFast->next;
            if (!pFast)
                return NULL;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pSlow == pFast) {
                pSlow = head;
                while (pSlow != pFast) {
                    pSlow = pSlow->next;
                    pFast = pFast->next;
                }
                return pSlow;
            }
        }
        return NULL;
    }
};
