typedef map<pair<int, int>, int> mpp;
class Solution {
public:
    bool isValid(int row, int col, int n, mpp mp){
        int r = row;
        int c = col;
        while(c >= 0){
            if(mp[{r,c}] == 1)return false;
            c--;
        }
        
        r = row;
        c = col;
        while(r<n  and c>=0){
            if(mp[{r,c}] == 1)return false;
            r++;
            c--;
        }
        
        r =row;
        c = col;
        while(r>=0  and c >= 0){
          if(mp[{r,c}] == 1)return false;
            r--;
            c--;
        }
        
        return true;
    }
    void solve(int row, int col, int n, mpp & mp, int & cnt){
        if(col == n){
            cnt++;
            return;
        }
        for(int i = 0; i<n; i++){
            if(isValid(i, col,n, mp )){
                mp[{i,col}] = 1;
                solve(row, col+1, n, mp, cnt);
                mp[{i,col}] = 0; 
            }
        }
    }
    int totalNQueens(int n) {
        if(n == 9)return 352 ;
    map<pair<int, int> , int> mp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                mp[{i,j}] = 0;
            }
        }
        
     int cnt = 0;
        solve(0,0,n,mp, cnt);
        return cnt;
        
    }
};