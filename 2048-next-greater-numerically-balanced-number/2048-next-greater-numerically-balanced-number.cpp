class Solution {
public:
    bool isValid(int n){
        int arr[10] ;
        for(int i = 0; i<=9; i++){
            arr[i] = 0;
        }
        while(n>0){
            int rem = n%10;
            if(rem == 0)return false;
            arr[rem]++;
            n = n/10;
        }
        for(int i = 1;i<10; i++){
            if(arr[i] != 0 and arr[i] != i)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(true){
            if(isValid(++n))return n;
        }
              }
};