class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int> v;
       int carry = 0;
        int i = num.size()-1;
        while(k>0 || i>=0){
            int rem = k%10;
            k /= 10;
            int p = 0;
            if(i >= 0)p = num[i--];
            int sum = carry + rem + p;
            if(sum > 9){
                v.push_back(sum%10);
                carry = 1;
            }
            else{
                v.push_back(sum);
                carry = 0;
            }
        }
        if(carry)v.push_back(carry);
        reverse(v.begin(), v.end());
        return v;
    }
};