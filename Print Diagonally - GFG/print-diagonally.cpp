//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{   vector<int> v;
		for(int i = 0; i<A[0].size(); i++){
		    int c = i;
		    int r = 0;
		    while(c>=0 and r<A.size()){
		        v.push_back(A[r][c]);
		        c--;
		        r++;
		    }
		}
		  if(N>1){
		        for(int i = 1; i<A.size(); i++){
		            int r = i;
		            int c = A.size()-1;
		            while(r<A.size() and c>=0){
		                v.push_back(A[r][c]);
		                r++;
		                c--;
		            }
		        }
		    }
		return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends