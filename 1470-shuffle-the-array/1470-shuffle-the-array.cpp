class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> v(2*n);
        int i = 0;
        int j = n;
        for(int k = 0; k<2*n; ){
            v[k++] = nums[i++];
            v[k++] = nums[j++];
            
        }
        return v;
    }
};