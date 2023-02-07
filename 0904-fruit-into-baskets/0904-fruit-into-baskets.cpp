class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int ans = -1;
        unordered_map<int,int> mp;
        while(j < fruits.size()){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)mp.erase(fruits[i]);
                    i++;
                }
                int c = 0;
                for(auto it : mp){
                    c += it.second;
                }
                ans = max(ans,c);
                j++;            
        }
        return ans;
    }
};