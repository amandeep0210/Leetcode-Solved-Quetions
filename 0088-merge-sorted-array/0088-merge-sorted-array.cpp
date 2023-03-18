class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1
            ;
        while(i>=0 and j>=0){
            if(nums1[i] == nums2[j]){
                nums1[k] = nums1[i];
                k--;
                nums1[k] = nums1[i];
                k--;
                i--;
                j--;
            }
            else if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else if(nums2[j] > nums1[i]){
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        
        if(j>=0){
            for(int p = 0; p <= j; p++){
                nums1[p] = nums2[p];
            }
        }
        if(i >= 0){
            for(int  p = 0; p <= i; p++){
                nums1[p] = nums1[p];
            }
        }
    }
};