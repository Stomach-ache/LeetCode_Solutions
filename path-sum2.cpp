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
    vector<vector<int> > hasPathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        int cnt = 0;
        if (root == NULL) return ans;
        if (root->left == NULL and root->right == NULL) {
            if(root->val == sum)
                ans[cnt++].push_back(root->val);
            return ans;
        }
        if (root->left != NULL) {
            ans = hasPathSum(root->left, sum-(root->val));
            for (size_t i = 0; i < ans.size(); i++)
                ans[i].push_back(root->val);
            return ans;
        }
        if (root->right != NULL) { 
            ans = hasPathSum(root->right, sum-(root->val));
            for (size_t i = 0; i < ans.size(); i++)
                ans[i].push_back(root->val);
            return ans;
        return ans;
    }
};