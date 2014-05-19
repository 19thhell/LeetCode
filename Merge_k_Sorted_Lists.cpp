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
        if (lists.size() == 0)
            return NULL;
        ListNode *head = NULL, **cur = &head, **min_p = NULL;
        while (true) {
            min_p = &lists[0];
            for (int i = 1;i < lists.size();i++)
                if (*min_p == NULL || lists[i] != NULL && lists[i]->val < (*min_p)->val)
                    min_p = &lists[i];
            if (*min_p == NULL)
                break;
            *cur = *min_p;
            *min_p = (*min_p)->next;
            cur = &((*cur)->next);
        }
        return head;
    }
};
