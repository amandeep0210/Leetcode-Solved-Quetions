class Solution {
public:
    int add(int num){
        int n = 0;
        while(num > 0 ){
            n += num%10;
            num /= 10;
        }
        return n;
    }
    int addDigits(int num) {
        while(floor(log10(num)+1) > 1){
            num = add(num);
        }
        return num;
    }
};