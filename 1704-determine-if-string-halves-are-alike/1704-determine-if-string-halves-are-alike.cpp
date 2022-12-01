class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1 = 0;
        int c2 = 0;
      for(int i = 0; i<s.length(); i++){
          if(i<s.length()/2){
              if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i'
                 or s[i] == 'o' or s[i] =='u' or s[i] == 'A'
                 or s[i] == 'E' or s[i] == 'I' or s[i] == 'O'
                 or s[i] =='U' )c1++;
          }
          else{
             if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i'
                or s[i] == 'o' or s[i] =='u' or s[i] == 'A'
                or s[i] == 'E' or s[i] == 'I' or s[i] == 'O'
                or s[i] =='U' )c2++; 
          }
      } 
      return c1 == c2;
    }
};