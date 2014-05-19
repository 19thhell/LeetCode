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
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int a, int b) {
        vector<TreeNode *> result;
        if (a > b) {
            result.push_back(NULL);
            return result;
        }
        if (a == b) {
            result.push_back(new TreeNode(a));
            return result;
        }
        vector<TreeNode *> tmpl, tmpr;
        for (int i = a;i <= b;i++) {
            tmpl = generateTrees(a, i - 1);
            tmpr = generateTrees(i + 1, b);
            for (int j = 0;j < tmpl.size();j++)
                for (int k = 0; k < tmpr.size();k++) {
                    TreeNode *p = new TreeNode(i);
                    p->left = tmpl[j];
                    p->right = tmpr[k];
                    result.push_back(p);
                }
        }
        return result;
    }
};
