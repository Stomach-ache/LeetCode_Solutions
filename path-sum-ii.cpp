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

    void dfs(TreeNode *root, vector<int> path, int curSum, int sum, vector<vector<int> > &ans) {
        if (root->left == NULL && root->right == NULL) {
            if (curSum + root->val == sum) {
                path.push_back(root->val);
                ans.push_back(path);
            }
            return ;
        }

        path.push_back(root->val);
        curSum += root->val;
        if (root->left != NULL) dfs(root->left, path, curSum, sum, ans);
        if (root->right != NULL) dfs(root->right, path, curSum, sum, ans);
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;

        if (root != NULL)
            dfs(root, vector<int>(), 0, sum, ans);

        return ans;
    }
};
