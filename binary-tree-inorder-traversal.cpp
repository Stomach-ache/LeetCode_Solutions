/*************************************************************************
    > File Name: BinaryTreeInorderTraversal.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年04月26日 星期六 12时30分19秒
    > Propose: 
 ************************************************************************/
#include <cmath>
#include <string>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		inline void creatTree(TreeNode);
};

class Solution {
public:
		vector<int> inorderTraversal(TreeNode *root) {
				int tail = 0;
				vector<TreeNode*> Stack;
				vector<int> ans;
				TreeNode *T = root;
				while (T != NULL || tail) {
						while (T != NULL) {
								tail++;
								Stack.push_back(T);
								T = T->left;
						}
						T = Stack[--tail];
						Stack.pop_back();
						ans.push_back(T->val);
						T = T->right;
				}

				return ans;
		}
};

int
main(void) {

}
