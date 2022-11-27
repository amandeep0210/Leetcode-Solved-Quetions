//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string addBinary(string A, string B)
	{
	  string result = "";
	  int c = 0;
	  int i = A.length()-1;
	  int j = B.length()-1;
	  while(i>=0 or j>=0){
	      if(i == -1 and j>=0){
	        int cnt = 0;
	          if(c == 1)cnt++;
	          if(B[j] == '1')cnt++;
	       
	        if(cnt == 2){
	              result.push_back('0');
	              c = 1;
	          }
	          else if(cnt == 1){
	              result.push_back('1');
	              c = 0;
	          }
	          else{
	              result.push_back('0');
	              c = 0;
	          }
	         j--;
	       
	      }
	      else if(j == -1 and i>=0){
	        int cnt = 0;
          if(c == 1)cnt++;
          if(A[i] == '1')cnt++;
	       
	        if(cnt == 2){
	              result.push_back('0');
	              c = 1;
	          }
	          else if(cnt == 1){
	              result.push_back('1');
	              c = 0;
	          }
	          else{
	              result.push_back('0');
	              c = 0;
	          }
	         i--;
	      }
	      else{
	          int cnt = 0;
	          if(c == 1)cnt++;
	          if(A[i]== '1')cnt++;
	          if(B[j] == '1')cnt++;
	          if(cnt == 3){
	              result.push_back('1');
	              c = 1;
	          }
	          else if(cnt == 2){
	              result.push_back('0');
	              c = 1;
	          }
	          else if(cnt == 1){
	              result.push_back('1');
	              c = 0;
	          }
	          else{
	              result.push_back('0');
	              c = 0;
	          }
	         i--;
	         j--; 
	      }
	      
	      
	  }
	  if(c == 1)result.push_back('1');
	  while(result[result.size()-1] == '0')result.pop_back();
	  reverse(result.begin(),result.end());
	   return result;
	   
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends