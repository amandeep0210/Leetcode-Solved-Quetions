//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
       vector<char>v1, v2;
       for(auto it : str){
           if(it >= 'A' and it <= 'Z')v1.emplace_back(it);
           else v2.emplace_back(it);
       }
       sort(v1.begin(), v1.end());
       sort(v2.begin(), v2.end());
       char arr[n] = {'0'};
       int j = 0;
       int k = 0;
       for(int i = 0; i<n; i++){
           if(str[i] >='A' and str[i] <= 'Z'){
               arr[i] = v1[j++];
           }
           else{
               arr[i] = v2[k++];
           }
       }
       string result= "";
       for(int i = 0; i<n; i++){
           result += arr[i];
       }
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends