class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp1,mp2;
        for(auto it : arr){
            mp1[it]++;
        }
        bool f =  true;
        for(auto it : mp1){
            if(mp2[it.second] == 0){
                mp2[it.second]++;
            }
            else{
                f =  false;
                break;
            }
        }
        return f;
    }
};