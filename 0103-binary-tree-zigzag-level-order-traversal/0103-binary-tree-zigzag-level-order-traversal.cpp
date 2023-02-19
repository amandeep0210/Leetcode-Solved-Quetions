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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root  == NULL) return v;
        else{
            queue<TreeNode* >q;
            q.push(root);
            bool flag = true;
            while(!q.empty()){
                vector<int> level;
                int s  = q.size();
                if(flag ==  true){
                  for(int i = 0 ;i<s; i++){
                      root = q.front();
                      q.pop();
                      level.push_back(root->val);
                      if(root->left)q.push(root->left);
                      if(root->right)q.push(root->right);
                  }
                 flag  =  false;   
                }
                else{
                    stack<int>st;
                     for(int i = 0 ;i<s; i++){
                      root = q.front();
                      q.pop();
                      st.push(root->val);
                      if(root->left)q.push(root->left);
                      if(root->right)q.push(root->right);
                  }
                    while(!st.empty()){
                        level.push_back(st.top());
                        st.pop();
                    }
                    flag = true;
                    
                }
                v.push_back(level);
            }
            return v;
        }
    }
};