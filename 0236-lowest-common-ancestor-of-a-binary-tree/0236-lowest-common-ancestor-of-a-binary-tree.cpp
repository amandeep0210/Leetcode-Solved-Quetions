/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
       if(!root)return NULL;
       if(root == p)return p;
       if(root == q)return q;
        TreeNode* L = solve(root->left, p, q);
        TreeNode* R = solve(root->right, p, q);
        if(L and R)return root;
        else if(L)return L;
        else return R;
       
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return  solve(root, p, q);
    }
};