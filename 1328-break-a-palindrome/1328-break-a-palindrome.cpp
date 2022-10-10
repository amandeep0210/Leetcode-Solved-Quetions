class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1)return "";
        int a = count(palindrome.begin(), palindrome.end(), 'a');
        if(a == palindrome.length() and a > 1){
            string k = palindrome.substr(0, palindrome.length()-1);
            k.push_back('b');
            return k;
        }
        if(n % 2 == 1 and a == n-1){
            if(palindrome[n/2] != 'a'){
            string k = palindrome.substr(0, palindrome.length()-1);
            k.push_back('b');
            return k;
            }
        }
      vector<char> v;
        int ind = -1;
        for(int i = 0; i<palindrome.size(); i++){
            if(palindrome[i]  != 'a'){
              ind  = i;
                break;
            }
        }
        if(ind == -1)return "";
        else{
            string k = "";
            for(int i = 0 ; i<ind; i++){
                k.push_back(palindrome[i]);
            }
            k.push_back('a');
            for(int i = ind+1 ; i<palindrome.size(); i++){
                k.push_back(palindrome[i]);
            }
            return k;
        }
    }
};