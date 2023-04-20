//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void preorder(Node* root, unordered_map<int, vector<int>>&adj){
        if(!root)return ;
        adj[root->data].push_back(root->data);
        if(root->left){
             adj[root->left->data].push_back(root->data);
             adj[root->data].push_back(root->left->data);
        }
        if(root->right){
            adj[root->right->data].push_back(root->data);
            adj[root->data].push_back(root->right->data);
        }
        preorder(root->left, adj);
        preorder(root->right, adj);
        
    }
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<int, vector<int>> adj;
        preorder(root,adj);
        
        queue<int> q;
        q.push(home);
        map<int,int> mp;
        int cnt = 0;
        int sum = 0;
        while(!q.empty() and k>=0){
            int s = q.size();
            for(int i = 0; i<s; i++){
                int val = q.front();
                q.pop();
                 mp[val] = 1;
                sum += val;
                for(auto it : adj[val]){
                    if(mp[it] == 0 and it != val)q.push(it);
                }
            }
            k--;
        }
        return sum;
        
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends