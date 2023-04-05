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
    TreeNode* temp1 = NULL, *temp2 = NULL, *prev = NULL;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(prev != NULL and prev->val > root->val){
            if(temp1 == NULL){
                temp1 = prev;
                temp2 = root;
            }
            else{
                temp2 = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root)return;
        inorder(root);
        swap(temp1->val, temp2->val);
    }
};