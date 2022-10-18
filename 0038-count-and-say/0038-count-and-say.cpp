class Solution {
public:
    string fn(string & s){
       string result = "";
       int cnt = 1;
       char k = s[0];
       for(int i = 1; i<s.size(); i++){
           if(s[i] == k)cnt++;
           else{
               result += (to_string(cnt));
               result.push_back(k);
               cnt = 1;
               k = s[i];
           }
       }
       result += (to_string(cnt));
       result.push_back(k);
      return result;  
    }
    string countAndSay(int n) {
       vector<string> prefix;
        prefix.push_back("1");
        for(int i = 1; i<30; i++){
            string s = fn(prefix[i-1]);
            // cout << s  << endl;
            prefix.push_back(s);
        }
        return prefix[n-1];
        
    }
};