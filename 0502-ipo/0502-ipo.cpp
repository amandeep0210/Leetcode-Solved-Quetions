#define pi pair<int,int> 
class Solution {
public:

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
     vector<pi> vp;
    for(int i = 0; i< profits.size(); i++){
        vp.push_back({capital[i], profits[i]});
    }
    sort(vp.begin(), vp.end());
    int n = profits.size();
    priority_queue<int> pq;
    int i = 0;
    while(k--){
    while(i < n and vp[i].first <= w){
        pq.push(vp[i].second);
        i++;
    }
        if(pq.size()){
            w += pq.top();
            pq.pop();
        }
    }
    return w;
    }
};