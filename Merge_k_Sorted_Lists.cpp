//Solution 1: using pointers and linear search for min value
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

//Solution 2: using divide and conquer
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
