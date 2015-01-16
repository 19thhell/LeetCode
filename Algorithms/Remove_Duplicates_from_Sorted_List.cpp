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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *a = head;
        while (a){
            while (a->next){
                if (a->val == a->next->val)
                    a->next = a->next->next;
                else break;
            }
            a = a->next;
        }
        return head;
    }
};
