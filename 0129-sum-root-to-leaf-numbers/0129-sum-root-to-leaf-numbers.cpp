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
    int sum = 0;
    void solve(TreeNode* root, int ans){
        if(!root){
            return;
        }
        if(!root->right and !root->left){
            ans *= 10;
            ans += root->val;
            sum += ans;
            return;
        }
        ans *= 10;
        ans += root->val;
        solve(root->left, ans);
        solve(root->right,ans);
        
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return sum;
    }
};