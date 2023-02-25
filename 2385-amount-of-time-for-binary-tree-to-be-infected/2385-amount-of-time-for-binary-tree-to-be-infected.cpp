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
    
    int maxi = 0;
    void inorder(TreeNode* root, vector<int> adj[]){
        if(!root)return;
        inorder(root->left, adj);
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].emplace_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].emplace_back(root->val);
        }
        inorder(root->right, adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        vector<int> adj[100000+1];
        inorder(root, adj);
        
        vector<int> vis(100000+1, 0);
        queue<int> q;
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            bool f = false;
            for(int i = 0; i<s; i++){
                auto nod = q.front();
                vis[nod] = 1;
                q.pop();
                for(auto it : adj[nod]){
                    if(vis[it] == 0){
                        f = true;
                        q.push(it);
                    }
                }
            }
            if(f)ans++;
        }
        return ans;
        
        
    }
};