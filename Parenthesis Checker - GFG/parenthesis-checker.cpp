//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       stack<char> st;
       for(int i = 0; i<x.length(); i++){
           if(st.size() == 0){
               st.push(x[i]);
           }
           else{
               char k1 = st.top();
               char k2 = x[i];
               if(k1 == '{' and k2 == '}')st.pop();
               else if(k1 == '(' and k2 == ')')st.pop();
               else if(k1 == '[' and k2 == ']')st.pop();
               else st.push(k2);
           }
       }
       return (!st.size());
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends