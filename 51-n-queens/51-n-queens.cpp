class Solution {
public:
    bool valid(int r, int c, vector<string> b, int n){
        int dr = r;
        int dc = c;
        while(r>= 0  and c >=0 ){
            if(b[r][c] == 'Q')return false;
            r--;
            c--;
        }
        
        c = dc;
        r = dr;
        while(c >=0 ){
             if(b[r][c] == 'Q')return false;
            c--;
        }
        
        c = dc;
        r = dr;
        while(r < n and c >=0 ){
             if(b[r][c] == 'Q')return false;
            r++ ;
            c--;
        }
        return true;
    }
    void solve(int col, vector<string> &b, vector<vector<string>> & result, int n){
        if(col == n){
            result.push_back(b);
            return;
        }
        for(int r = 0; r<n; r++){
            if(valid(r, col, b, n)){
                b[r][col] = 'Q';
                solve(col+1, b, result, n);
                b[r][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n,  '.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        solve(0, board,result, n);
        return result;
    }
};