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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(arr, 0, arr.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &num, int left, int right){
        if (left > right)
            return NULL;
        else {
            int mid = (left + right) / 2;
            TreeNode *tmp = new TreeNode(num[mid]);
            tmp->left = sortedArrayToBST(num, left, mid - 1);
            tmp->right = sortedArrayToBST(num, mid + 1, right);
            return tmp;
        }
    }
};
