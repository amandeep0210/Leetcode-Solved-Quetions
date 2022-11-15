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
    int countNodes(TreeNode* root) {
       if(!root)return 0;
        int l =  1;
        int r =  1;
        TreeNode* L =  root->left;
        TreeNode* R =  root->right;
        while(L){
            L =  L->left;
            l += 1;
        }
        while(R){
            R =  R->right;
            r += 1;
        }
        
        if(l == r)return pow(2, l)-1 ;
        else{
            return 1 + countNodes(root->left) +  countNodes(root->right);
        }
    }
};