class Solution {
public:
    int maximum69Number (int num) {
       vector<int> v;
        while(num>0){
            v.push_back(num%10);
            num = num/10;
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }
        // reverse(v.begin(), v.end());
         num = 0;
        for(int i = 0; i<v.size(); i++){
            num = num*10 + v[i];
        }
        return num;
        
    }
};