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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return dfs(preorder, inorder, 0, 0, inorder.size());
    }

    /* $cur: holds the current index of node to be added to binary tree
     * [$l, $r): index of nodes in this subtree
     */
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int cur, int l, int r) {
        int sz = r - l;
        if (sz == 0) return NULL;

        TreeNode *head = new TreeNode(preorder[cur]);

        int i = l;
        for (; i < r; ++i) if (inorder[i] == head->val) break;

        // build the left subtree
        head->left = dfs(preorder, inorder, cur + 1, l, i);
        // build the rigth subtree
        head->right = dfs(preorder, inorder, cur + i - l + 1, i + 1, r);

        return head;
    }
};
