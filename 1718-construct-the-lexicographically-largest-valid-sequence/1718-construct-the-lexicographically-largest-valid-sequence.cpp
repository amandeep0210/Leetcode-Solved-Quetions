class Solution {
public:
    vector<int>seen;
    bool dfs(vector<int>&ans, int idx)
    {
        //Built the answer
        if(idx == ans.size()) return true;
		
        //If already placed a num at the idx location
        if(ans[idx] > 0) return dfs(ans, idx + 1);
		
	
        //Greedily trying to place nums from n to 1 so as to form lexographically largest ans
        for(int i = seen.size() - 1; i >= 1; i--)
        {
            if(seen[i]) continue;   //Already placed this integer in the answer
			
            //Double number can't be placed then continue
            if(i != 1 && (i + idx >= ans.size() || ans[i + idx] )) continue; 
			
            seen[i] = 1;   // Mark seen
            ans[idx] = i;  //Place integer to ans position idx
            if(i != 1) ans[idx + i] = i;  //Place the other one
            //here idx + i is = so that distance become i only
			
            if(dfs(ans, idx + 1)) return true;  // Check if we can have correct sol if we place integer i at idx location
            
			seen[i] = 0;  // Backtrack
            ans[idx] = 0; // Backtrack
            if(i != 1) ans[idx + i] = 0; //Backtrack
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
         seen.resize(n + 1, 0);
         vector<int> ans (2 * n - 1, 0);
         dfs(ans, 0);
         return ans;
    }
};