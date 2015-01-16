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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
private:
    ListNode *mergeKLists(vector<ListNode *> &lists, int left, int right) {
        int mid = left + (right - left) / 2;
        if (left > right)
            return NULL;
        else if (left == right)
            return lists[left];
        return mergeTwoLists(mergeKLists(lists, left, mid), mergeKLists(lists, mid + 1, right));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode **p = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                *p = l1;
                l1 = l1->next;
            }
            else {
                *p = l2;
                l2 = l2->next;
            }
            p = &((*p)->next);
        }
        *p = l1 ? l1 : l2;
        return head;
    }
};
