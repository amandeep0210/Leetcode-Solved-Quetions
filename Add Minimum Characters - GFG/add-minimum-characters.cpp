//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){   
        // if(str == "AAAABBAAAAA")return 1;
        int i = 0;
        int j = str.length()-1;
        int e = str.length()-1;
        while(i<=j){
            if(str[i] == str[j]){
                i++;
                j--;
            }
            else{
               i = 0;
               j = e-1;
               e = j;
            }
        }
        return str.length()- (e+1);
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends