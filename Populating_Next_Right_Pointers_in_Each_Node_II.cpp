/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)
            return;
        TreeLinkNode *p = root, *q = NULL, *next_root = NULL;
        while(p) {
            if (p->left) {
                if (q)
                    q->next = p->left;
                q = p->left;
                if (!next_root)
                    next_root = q;
            }
            if (p->right) {
                if (q)
                    q->next = p->right;
                q = p->right;
                if (!next_root)
                    next_root = q;
            }
            p = p->next;
        }
        connect(next_root);
    }
};
