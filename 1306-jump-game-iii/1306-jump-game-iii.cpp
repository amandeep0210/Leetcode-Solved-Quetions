class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            vis[ind] = 1;
            if(arr[ind] == 0)return true;
            if(ind + arr[ind] < arr.size() and !vis[ind+arr[ind]])q.push(ind+arr[ind]);
            if(ind - arr[ind] >= 0 and !vis[ind-arr[ind]])q.push(ind-arr[ind]);
        }
        return false;
    }
};