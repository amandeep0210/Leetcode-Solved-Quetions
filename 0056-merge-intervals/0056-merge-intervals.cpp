class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> result;
        result.push_back(v[0]);
        for(int i = 1; i<v.size(); i++){
            int n = result.size()-1;
            int first = result[n][0];
            int second = result[n][1];
            int curr1 = v[i][0];
            int curr2 = v[i][1];
            if(curr1 >= first and curr1 <= second){
                result[n][0] = min(first, curr1);
                result[n][1] = max(second, curr2);
            }
            else{
                result.push_back(v[i]);
            }
            
        }
        return result;
    }
};