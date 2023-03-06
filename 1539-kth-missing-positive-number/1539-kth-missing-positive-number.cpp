class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    unordered_map<int,int> mp;
        for(auto it : arr)mp[it]++;
        int cnt = 0;
        int i = 1;
        while(true){
            if(mp[i] == 0){
                cnt++;
            }
            if(cnt == k)return i;
            i++;
        }
    }
};