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
//Straight forward
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
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while (pA) {
            lenA++;
            pA = pA->next;
        }
        while (pB) {
            lenB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        while (lenA > lenB) {
            lenA--;
            pA = pA->next;
        }
        while (lenA < lenB) {
            lenB--;
            pB = pB->next;
        }
        while (pA && pB) {
			if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};
