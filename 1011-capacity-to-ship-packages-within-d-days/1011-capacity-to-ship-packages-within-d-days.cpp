class Solution {
public:
    bool check(int m, int d, vector<int>&weights){
        int days = 1;
        int cap = 0;
        for(int i = 0; i<weights.size(); i++){
            if(weights[i] > m)return false;
            cap += weights[i];
            if(cap > m){
                days++;
                cap = weights[i];
            }
        }
        return (days <= d);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(),0);
        int s = weights[0]-1;
        int e = sum;
        while(e-s>1){
            int m = s + (e - s)/2;
            if(check(m, days, weights)){
                e = m;
            }
            else{
                s = m;
            }
        }
        return e;
    }
};