class Solution {
public:
    string convert(string s, int numRows) {
       int r = numRows;
        if(r == 1)return s;
       int c = s.length();
       char k = '1';
       vector<vector<char>> mat(r, vector<char>(c, k));
        int k1 = 0;
        int k2 = 0;
        bool f = true;
        int i = 0;
      while(i<s.length()){
          if(k1 == 0){
              mat[k1][k2] = s[i++];
              k1++;
              f = true;
          }
          else if(k1 == r-1){
              mat[k1][k2] = s[i++];
              f =  false;
              k1--;
              k2++;
          }
          else{
              if(f == true){
                  mat[k1][k2] = s[i++];
                  k1++;
              }
              else{
                  mat[k1][k2] = s[i++];
                  k1--;
                  k2++;
              }
          }
      }
      string res = "";
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(mat[i][j] != '1')res.push_back(mat[i][j]);
            }
        }
       
       return res;
        
        
    }
};