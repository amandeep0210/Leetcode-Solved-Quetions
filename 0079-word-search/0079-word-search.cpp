typedef vector<vector<char>> vv;
class Solution {
public:
     map<pair<int, int>, int> mp;
    void solve(int ind, string &word, int c, vv & board, int i, int j, bool & f, int n, int m){
        
        if(board[i][j] == word[ind] and mp[{i,j}] == 0){
            mp[{i,j}] = 1;
            c++;
            ind++;
        if(c == word.length()){
            f =  true;
            return;
        }
        
        if((i-1>=0 and i-1<n) and (j>=0  and j< m) and (mp[{i-1, j}]  == 0)){
            solve(ind,word, c, board, i-1,j,f,n,m);
        }
        if((i+1>=0 and i+1<n) and (j>=0  and j< m) and (mp[{i+1, j}]  == 0)){
            solve(ind,word, c, board, i+1,j,f,n,m);
        }
        if((i>=0 and i<n) and (j-1>=0  and j-1< m) and (mp[{i, j-1}]  == 0)){
            solve(ind,word, c, board, i,j-1,f,n,m);
        }
        if((i>=0 and i<n) and (j+1>=0  and j+1< m) and (mp[{i, j+1}]  == 0)){
            solve(ind,word, c, board, i,j+1,f,n,m);
        }
            
        mp[{i,j}] = 0;
            
        }
        return;    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int c = 0;
        bool f = false;
        int n = board.size();
        int m = board[0].size();
       for(int i = 0; i<board.size(); i++){
           for(int  j = 0; j<board[0].size(); j++){
               solve(0, word, c, board, i, j, f, n, m);
               if(f == true)return true;
           }
       }
        return false;
    }
};