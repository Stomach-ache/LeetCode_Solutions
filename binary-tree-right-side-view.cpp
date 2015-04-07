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
typedef pair<TreeNode*, int> pii;
    vector<int> rightSideView(TreeNode *root) {
        if (root == NULL) return vector<int> ();

        // calculate the depth of the given binary tree.
        int depth = dfs(root);
        // store every level's nodes from left to right.
        vector<int> vtmp[depth];

        // using breadth first search.
        queue<pii> Q;
        Q.push(pii(root, 0));
        while (!Q.empty()) {
            pii tmp = Q.front(); Q.pop();
            TreeNode *p = tmp.first;
            vtmp[tmp.second].push_back(p->val);
            if (p->left  != NULL) Q.push(pii(p->left,  tmp.second+1));
            if (p->right != NULL) Q.push(pii(p->right, tmp.second+1));
        }

        // take the rightmost node of every level.
        vector<int> ans;
        for (int i = 0; i < depth; i++) if (vtmp[i].size()) ans.push_back(vtmp[i].back());
        return ans;
    }

    /* calculate the depth of the tree rooted $root. */
    int dfs(TreeNode *root) {
        int ans = 1;
        if (root->left != NULL) ans = max(ans, dfs(root->left)+1);
        if (root->right != NULL) ans = max(ans, dfs(root->right)+1);
        return ans;
    }
};
