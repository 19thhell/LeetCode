//Elegant solution
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        if (!pA || !pB)
            return NULL;
        while (pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;
            if (pA == pB)
                break;
            if (!pA)
                pA = headB;
            if (!pB)
                pB = headA;
        }
        return pA;
    }
};
