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
    int ans = 0;
    void solve(TreeNode* root , char dir, int len){
        if(root == NULL)return;
        ans = max(ans, len);
        if(dir == 'L'){
            solve(root->left, dir, 1);
            solve(root->right, 'R', len+1);
        }
        else{
            solve(root->right, dir, 1);
            solve(root->left, 'L', len+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root->left, 'L', 1);
        solve(root->right, 'R', 1);
        return ans;
    }
};