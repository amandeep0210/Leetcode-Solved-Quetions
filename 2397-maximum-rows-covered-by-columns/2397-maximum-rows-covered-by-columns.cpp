class Solution {
public:
    int valid(vector<int> &colm, vector<vector<int>> &mat){
        int res = 0;
        unordered_map<int, int> mp;
        for(auto it : colm){
            mp[it]++;
        }
        for(int i = 0; i<mat.size(); i++){
            bool f =  true;
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    if( !mp[j]){
                        f =  false;
                        break;
                    }
                }
            }
             if(f)res++;
        }
        return res;
    }
    void solve(vector<int> &colm, vector<vector<int>> & mat, int &ans, int cols, int ind){
        if(cols == 0){
            ans = max(valid(colm, mat), ans);
            return;
        }
        for(int i = ind; i<mat[0].size(); i++){
            colm.push_back(i);
            solve(colm, mat, ans, cols-1, i+1);
            colm.pop_back();
        }
        
        
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
      int ans = 0 ;
      vector<int> colm;
      
      solve(colm, mat, ans, cols, 0);
        return ans;
        
    }
};