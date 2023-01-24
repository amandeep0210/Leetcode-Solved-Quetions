//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> result;
    void fn(int n,int op, int cl, string s){
        if(op == n and cl == n){
            result.push_back(s);
            return ;
        }
        if(op > n || cl > n)return;
        // try all the possible ways:
        if(op < n){
            // s += '(';
            fn(n, op+1, cl, s+'(');
        }
        if(cl < op){
            // s += ')';
            fn(n, op , cl+1, s+')');
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        string s = "";
        fn(n,0,0,s);
        return result;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends