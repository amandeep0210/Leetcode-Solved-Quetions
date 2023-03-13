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
    bool sym(TreeNode* root){
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});
        while(!q.empty()){
            int sum = 0;
            int s = q.size();
            for(int i = 0; i< s; i++){
                auto it = q.front();
                int line = it.second;
                sum += line;
                root = it.first;
                q.pop();
                if(root->left)q.push({root->left,line-1});
                if(root->right)q.push({root->right ,line+1});
            }
            if(sum != 0)return false;
        }
        return true;   
    }
public:
    bool isSymmetric(TreeNode* root) {
        // i am trying to solve it using the iterative way 
        // i will follow the level order traversal
        // i will make the co-ordinates and will add all the cor-ordinates of particular level
        /*
        first of all i will check wheter it is symmertic in shape or not irrespective of the values
        */
        if(sym(root) == false)return false;
        else{
            TreeNode* temp =  root ;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                vector<int>v;
                int s = q.size();
                if(root !=temp){
                    if(s%2 == 1)return false;
                }
                for(int i = 0; i<s; i++){
                    root =  q.front();
                    q.pop();
                    v.push_back(root->val);
                    if(root->left)q.push(root->left);
                    if(root->right)q.push(root->right);
                }
                int i = 0;
                int j = s-1;
                while(i<=j){
                    if(v[i] != v[j]){
                        return false;
                    }
                    i++;
                    j--;
                }
            }
            return true;
        }
       
        
    }
};