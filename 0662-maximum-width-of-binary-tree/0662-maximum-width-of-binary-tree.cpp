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
    public :
  int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned int> v;
        unsigned int max_width = 1;
        queue<pair<TreeNode*,unsigned int>> qu;
        qu.push({root, 0});
        int counter = 1;
        
        while (!qu.empty()){
            while (counter > 0){
                pair<TreeNode*,unsigned int> p = qu.front();
                qu.pop();
                counter--;
                TreeNode* node = p.first;
                if (node->left != NULL)
                {
                    qu.push({node->left, 2*p.second+1});
                    v.push_back(2*p.second+1);
                }
                if (node->right != NULL){
                    qu.push({node->right, 2*p.second+2});
                    v.push_back(2*p.second+2);
                }
            }
            counter = qu.size();
            int n = v.size();
            
            unsigned int width=0;
            if (n > 0)
                width = v[n-1]-v[0] + 1;
            if (width > max_width)
                max_width = width;
            v.clear();
        }
        return max_width;
    }
};