class Solution {
public:
    int longestPalindrome(vector<string>& words) {
    unordered_map<string,int> mp,mp1;
        int cnt = 0;
        
        for(int i = 0; i<words.size();i++){
            if(words[i][0] == words[i][1]){
                mp1[words[i]]++;
            }
            else{
                string s1 = words[i];
                reverse(s1.begin(),s1.end());
                if(mp[s1]){
                    cnt += 4;
                    mp[s1]--;
                }
                else{
                    mp[words[i]]++;
                }
            }
        }
        bool f =  false;
        for(auto it : mp1){
            if(it.second%2 == 0){
                cnt += it.second*2;
            }
            else{
                 int k = it.second-1;
                cnt += k*2;
            }
        }
        for(auto it : mp1){
            if(it.second %2 == 1){
              cnt += 2;
                break;
            }
        }
        return cnt;
    }
};