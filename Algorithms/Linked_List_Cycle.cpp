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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *pSlow = head;
        ListNode *pFast = head;
        while (pFast) {
            pFast = pFast->next;
            if (!pFast)
                return false;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pSlow == pFast)
                return true;
        }
        return false;
    }
};
