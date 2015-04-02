// attention: average O(1) time means amortized complexity is O(1).

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
        getLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ans = st.top(); st.pop();
        getLeft(ans->right);
        return ans->val;
    }

    // put all nodes of the leftest path from $root to leaf.
    void getLeftPath(TreeNode *root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
private:
    stack<TreeNode *> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
