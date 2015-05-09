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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode* tail = head;
        while (tail->next)
            tail = tail->next;
        while (head != tail) {
            ListNode* rec = tail->next;
            ListNode* next = head->next;
            tail->next = head;
            head->next = rec;
            head = next;
        }
        return tail;
    }
};
