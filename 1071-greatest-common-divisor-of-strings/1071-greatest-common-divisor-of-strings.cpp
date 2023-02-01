class Solution {
public:
    bool check(string &t, string &s1, string &s2){
        bool f1= false;
        bool f2 = false;
        string temp1 = t;
        string temp2 = t;
        while(temp1.length() < s1.length()){
            temp1 += t;
        }
        while(temp2.length() < s2.length()){
            temp2 += t;
        }
        return(temp1 == s1 and temp2 == s2);
        
    }
    string gcdOfStrings(string str1, string str2) {
        int len = min(str1.length(), str2.length());
        string ans = "";
        string temp = "";
        for(int i = 0; i<len; i++){
            if(str1[i] != str2[i]){
                break;
            }
            else{
                temp += str1[i];
                if(check(temp, str1, str2)){
                    ans = temp;
                } 
            }
        }
        return ans;
    }
};