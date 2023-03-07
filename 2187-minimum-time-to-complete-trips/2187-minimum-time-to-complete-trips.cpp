class Solution {
public:
    bool isPossible(long long mid, vector<int>& time, int totalTrips){
        long long trips = 0;
        for(int i = 0; i<time.size(); i++){
            trips += floor(1.0*mid/time[i]);
        }
        return (trips >= totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxi = *max_element(time.begin(), time.end());
        long long l = 0;
        long long r = maxi*totalTrips;
        while(r-l>1){
            long long mid = l + (r-l)/2;
            if(isPossible(mid, time, totalTrips)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return r;
    }
};