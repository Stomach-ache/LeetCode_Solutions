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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) return false;
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }
};
