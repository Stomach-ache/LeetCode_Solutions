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
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;

        int sum = 0; // initialized $sum to zero
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode *root, int curVal, int &sum) {
        if (root->left == NULL && root->right == NULL) {
            curVal = curVal * 10 + root->val;
            sum += curVal; // update $sum
            return ;
        }
        if (root->left != NULL) dfs(root->left, curVal*10 + root->val, sum);
        if (root->right != NULL) dfs(root->right, curVal*10 + root->val, sum);
    }

private:
    // $sum holds the sum of all root to leaf numbers.
    int sum;
};
