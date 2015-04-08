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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        
        dfs(root, 1, res);
        return res;
    }
    
    void dfs(TreeNode *root, int dep, vector<vector<int> > &res) {
        if (dep > res.size()) res.resize(dep);
        res[dep-1].push_back(root->val);
        
        if (root->left != NULL)  dfs(root->left, dep+1, res);
        if (root->right != NULL) dfs(root->right, dep+1, res);
    }
};
