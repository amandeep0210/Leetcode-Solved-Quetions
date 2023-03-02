class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        char curr = chars[0];
        int cnt = 0;
        int n = chars.size();
        for(int i = 0; i<n; i++){
            if(chars[i] == curr){
                cnt++;
            }
            else{
                chars[j++] = curr;
                if(cnt > 1){
                string temp = to_string(cnt);
                // reverse(temp.begin(), temp.end());
                int k = 0;
                while(k < temp.size() and j < n){
                    chars[j++] = temp[k++];
                }
                }
            curr = chars[i];
            cnt = 1;
            }
           
        }
        chars[j++] = curr;
         if(cnt > 1){
        string temp = to_string(cnt);
        // reverse(temp.begin(), temp.end());
        int k = 0;
        while(k < temp.size() and j < n){
            chars[j++] = temp[k++];
        }
        }
        
        return j;
    }
};