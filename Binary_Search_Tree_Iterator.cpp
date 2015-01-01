/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            stk.push(cur);
            if (cur->left != nullptr) {
                cur = cur->left;
            }
            else break;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *next = stk.top(), *cur = next;
        stk.pop();
        if (cur->right != nullptr) {
            cur = cur->right;
            while (cur != nullptr) {
                stk.push(cur);
                if (cur->left != nullptr) {
                    cur = cur->left;
                }
                else break;
            }
        }
        return next->val;
    }
private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
