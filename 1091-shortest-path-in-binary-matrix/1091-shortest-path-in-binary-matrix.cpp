class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 1e9));
        if(grid[0][0] == 0){
            dist[0][0] = 0;
            pq.push({0, {0,0}});
        }
        int n = grid.size();
        int m = grid[0].size();
      
        while(!pq.empty()){
            auto it  = pq.top().second;
            int dis = pq.top().first;
            int r = it.first;
            int c = it.second;
            pq.pop();
            for(int  i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                int R = r + i;
                int C = c + j;
                if(R>=0 and R < n and C >=0 and C < m){
                    if(grid[R][C] == 0){
                        if(dis + 1 < dist[R][C]){
                            dist[R][C] = dis + 1;
                            pq.push({dist[R][C], {R,C}});
                        }
                    }
                  }
                }
            }
        }
         if(dist[n-1][m-1] == 1e9)return -1;
         else return dist[n-1][m-1]+1;
    }
};