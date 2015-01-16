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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *cur = head, *end = head;
        while (n--) {
            end = end->next;
        }
        if (!end)
            return head->next;
        while (end->next) {
            cur = cur->next;
            end = end->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};
