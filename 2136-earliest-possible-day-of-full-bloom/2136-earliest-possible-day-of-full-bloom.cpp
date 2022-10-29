
class Solution {
public:
    
        int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
       vector<pair<int, int>> vp;
            for(int i = 0; i<plant.size(); i++){
                vp.push_back({grow[i],plant[i]});
            }
            sort(vp.begin(), vp.end());
       int result = 0;
            for(auto it : vp){
                result = max(result, it.first) + it.second;
            }
            return result;
}
};