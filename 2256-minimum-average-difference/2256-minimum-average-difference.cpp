class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       int n = nums.size();
       if(n == 1) return 0;
       
       long long int p[n],s[n];
        p[0] = nums[0];
        s [n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            p[i] = p[i-1] + nums[i];
        }
        for(int i = n-2; i>=0; i--){
            s[i] = s[i+1] + nums[i];
        }
        long long int diff = INT_MAX;
        int ind = INT_MAX;
        for(int i = 1; i<n-1; i++){
            long long int avg = abs(p[i]/(i+1)-s[i+1]/(n-i-1));
            if(avg < diff){
                ind = i;
                diff = avg;
            }
            else if(avg == diff){
                ind = min(ind, i);
            }
            
            // cout << diff << endl;
        }
        
        long long int avg1 = abs(nums[0] - s[1]/(n-1));
        if(avg1<diff){
            diff = avg1;
            ind = 0;
        }
        else if(avg1 == diff){
            ind = 0;
        }
        // cout << diff << endl;
        long long int avg2 = p[n-1]/n;
        if(avg2<diff){
            diff = avg2;
            ind = n-1;
        }
        else if(diff == avg2){
            ind = min(ind, n-1);
        }
        // cout <<diff << endl;
        return ind;
    }
    
};