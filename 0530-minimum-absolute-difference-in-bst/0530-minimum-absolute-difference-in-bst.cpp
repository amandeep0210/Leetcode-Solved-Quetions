/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void inorder(TreeNode* node, TreeNode*& prev, int& mini) {
        if (node == NULL) {
            return;
        }
        inorder(node->left, prev, mini);
        if (prev != NULL) {
            mini = min(mini, node->val - prev->val);
        }
        prev = node;
        inorder(node->right, prev, mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, mini);
        return mini; 
    }
};