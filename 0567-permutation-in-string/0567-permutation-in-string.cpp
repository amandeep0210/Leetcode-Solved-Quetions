class Solution {
public:
    bool check(int vis1[], int vis2[]){
        for(int i = 0; i<26; i++){
            if(vis1[i] !=  vis2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int k =  s1.size();
        int j = 0; 
        int i = 0;
        int vis1[26] = {0};
        for(auto it :  s1){
            vis1[it - 'a']++;
        }
        int vis2[26] = {0};
        while(j < s2.length()){
            vis2[s2[j] - 'a']++;
            if(j-i+1 < k)j++;
            else if(j-i+1 == k){
                if(check(vis1, vis2))return true;
                
                // slide the window
                vis2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};