class Solution {
public:
    int getMaxLen(vector<int>& arr) {
           int n = arr.size();
           int i = 0;
           int j = 0;
           int s = -1;
           int e = -1;
           int cnt = 0;
           int ans = 0;
           while(j<n){
               if(arr[j] > 0)j++;
               else if(arr[j] < 0){
                   cnt++;
                   if(s == -1)s = j;
                   e = j;
                   j++;
               }
               else if(arr[j] == 0){
                   int len = j-i;
                
                   if(cnt%2 == 0)ans = max(ans, len);
                   else{
                       int l1 = s-i+1;
                       int l2 = j-e;
                       ans = max(ans,max(len-l1, len-l2));
                   }
                   j++;
                   i = j;
                   cnt = 0;
                   s = -1;
                   e = -1;
               }
           }
           if(j-i > 0){
               int len = j-i;
               if(cnt%2 == 0)ans =  max(ans, len);
               else{
               
                    int l1 = s-i+1;
                       int l2 = j-e;
                       ans = max(ans , max(len-l1, len-l2));
               }
           }
           return ans;
    }
};