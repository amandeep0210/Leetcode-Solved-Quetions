class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int m1 = INT_MAX;
        for(int i = 0; i<prices.size(); i++){
          m1 = min(m1, prices[i]);
          maxi = max(maxi, prices[i] - m1);

        }
        return maxi;
    }
};