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
    bool preorder(TreeNode* root, int k,  bool & f, TreeNode* check){
        if(!root)return false;
        if(root->val == k and root != check)return true;
        return preorder(root->left, k, f, check) or preorder(root->right, k, f, check);
    }
    void inorder(TreeNode* root, int k, bool & f, TreeNode* temp){
        if(!root)return;
        if(f ==  true)return;
        inorder(root->left, k, f, temp);
        if(preorder(temp, k - root->val , f, root) == true){
            f = true;
            return;
        };
        inorder(root->right, k, f, temp);
        
    }
    bool findTarget(TreeNode* root, int k) {
        bool f = false;
        TreeNode* temp =  root;
        inorder(root, k, f, temp);
        return f;
    }
};