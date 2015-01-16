/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode **pHead = &head;
        return buildTree(pHead, listLength(head));
    }
private:
    int listLength(ListNode *head) {
        int n = 0;
        while (head) {
            head = head->next;
            n++;
        }
        return n;
    }

    TreeNode *buildTree(ListNode **pHead, int n) {
        if (!n)
            return NULL;
        TreeNode *tree = new TreeNode(0);
        tree->left = buildTree(pHead, n / 2);
        tree->val = (*pHead)->val;
        *pHead = (*pHead)->next;
        tree->right = buildTree(pHead, n - n / 2 - 1);
        return tree;
    }
};
