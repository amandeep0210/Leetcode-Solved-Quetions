class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        string ans = "";
        while(i>=0 || j>=0){
             int a1 = 0;
             int a2 = 0;
             if(i>=0){
                 a1 = a[i--]-'0';
             }
            if(j>=0){
                a2 = b[j--]-'0';
            }
            if(a1*a2 == 1){
                if(c == 1){
                    ans += '1';
                    c = 1;
                }
                else{
                    ans += '0';
                    c = 1;
                }
            }
            else{
                if(a1 != a2){
                    if(c == 1){
                        ans += '0';
                        c = 1;
                    }
                    else{
                        ans += '1';
                        c = 0;
                    }
                }
                else{
                    if(c == 1){
                        ans += '1';
                        c = 0;
                    }
                    else{
                        ans += '0';
                        c = 0;
                    }
                }
            }
            
            
        }
        if(c)ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};