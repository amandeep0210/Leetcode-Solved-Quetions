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
    vector<int>v1;
    void inorder(TreeNode* root){
        if(!root)return ;
        inorder(root->left);
        v1.emplace_back(root->val);
        inorder(root->right);
    }
    void Inorder(TreeNode* root, int a1, int a2){
        if(!root)return;
        Inorder(root->left, a1, a2);
        if(root->val == a1)root->val = a2;
        else if(root->val == a2)root->val = a1;
        Inorder(root->right, a1, a2);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int>v2(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int a1, a2;
        bool f = false;
        for(int i = 0; i<v2.size(); i++){
            if(v1[i] != v2[i]){
                if(f == false){
                a1 = v1[i];
                 f = true;
                }
                else{
                a2 = v1[i];
                break;
                }
            }
        }
        Inorder(root, a1, a2);
    }
};