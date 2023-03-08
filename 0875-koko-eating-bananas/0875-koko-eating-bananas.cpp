class Solution {
public:
    bool ispossible(long long m , int h, vector<int>& piles){
        long long hour = 0;
        for(auto it : piles){
            if(it <= m)hour++;
            else{
                hour += it/m;
                if(it%m != 0)hour++; 
            }
        }
        return (hour <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 0;
        long long r = *max_element(piles.begin(), piles.end());
        while(r-l>1){
            long long m = l + (r-l)/2;
            if(ispossible(m, h, piles)){
                r = m;
            }
            else{
                l = m;
            }
        }
        return r;
    }
};