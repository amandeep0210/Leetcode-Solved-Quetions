class Solution {
public:
    int totalMoney(int n) {
        int total = ceil(n/7.0);
        int rem = n%7;
        if(total == 1){
            return n*(n+1)/2;
        }
        int sum = 0;
        if(rem){
         for(int i = 1; i<total ; i++){
            sum += (7*(i+3));
        }   
        }
        else{
            for(int i = 1; i<=total ; i++){
            sum += (7*(i+3));
        }
        }
        
        // cout << sum << endl;
        int i = 0;
        while(rem--){
            sum += (total + i);
                i++;
        }
       
        return sum;
    }
};