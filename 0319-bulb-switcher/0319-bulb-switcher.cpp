class Solution {
public:
    int bulbSwitch(int n) {
      long long ans = 1;
      long long add = 3;
      long long num = 0;
      if(n == 0)return 0;
      while(true){
          long long s = num+1;
          long long e = num+add;
          if(n>=s and n<=e)return ans;
          ans++;
          add += 2;
          num = e;
      }
    }
};