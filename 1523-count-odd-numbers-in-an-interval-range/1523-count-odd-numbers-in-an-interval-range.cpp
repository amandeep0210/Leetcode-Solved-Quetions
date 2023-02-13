class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        for(int i = low; i<= high; i++){
            (i%2) ? cnt += 1 : cnt += 0;
        }
        return cnt;
    }
};