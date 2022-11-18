class Solution {
public:
    bool isUgly(int n) {
       if(n == 1)return true;
       if(n == 0)return false;
       if(n%2 and n%5 and n%3)return false;
      bool f1 = false;
      bool f2 = false;
      bool f3 = false;
       if(n%2 == 0){
         f1 = isUgly(n/2);  
       }
       if(n%5 == 0){
         f2 = isUgly(n/5);
       }
        if(n%3 == 0){
          f3=  isUgly(n/3);
        }
        return f1 || f2 || f3;
    }
};