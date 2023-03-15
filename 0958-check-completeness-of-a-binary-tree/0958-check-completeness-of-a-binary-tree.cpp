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
    int solve(TreeNode* root, int cor){
        if(!root)return 0 ;
        root->val = cor;
        int l = 1+ solve(root->left, cor-1);
        int r = 1+ solve(root->right, cor+1);
        return max(l, r);
    }
    bool isCompleteTree(TreeNode* root) {
        int height = solve(root, 0);
        vector<char>v;
        vector<int> v1;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        int digit = -1;
        bool flag = false;
        while(q.size()){
            int s = q.size();
            if(s%2 and cnt != 1 and cnt != height)return false;
            int sum = 0;
            int ind = -1;
            int prev = -1;
            for(int i = 0; i< s; i++){
                root = q.front();
                q.pop();
                if(cnt ==  height-1 and !root->left and  i == 0)return false;
                sum += root->val;
                if(cnt == height-1){
                    if(root->right and !root->left)return false;
                    if(!root->left || !root->right and flag == false){
                        ind = i;
                        flag = true;
                    }
                   
                }
                 if(i > ind and flag == true and (root->left || root->right))return false;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            if(cnt != height and sum != 0)return false;
            cnt++;
        }
        return true;
    }
};