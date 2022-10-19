class comp{
     public:
     bool operator() (pair<int, string> p1, pair<int, string>&p2) { // top and current
      if(p1.first == p2.first) return p1.second > p2.second;
      
      return p1.first < p2.first;
    }
    };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it : words){
            mp[it]++;
        }
        priority_queue<pair<int, string> ,vector<pair<int, string>>, comp> pq; 
        for(auto it : mp){
            pq.push({it.second,it.first});
//             // cout << it.second << " " <<it.first << endl;
//                 if(k>0){
//                 pq.push({it.second, it.first});
//                     k--;
//                 }
//                 else{
//                     if(pq.top().first < it.second){
//                         pq.pop();
//                         pq.push({it.second, it.first});
//                     }
//                 }
                 
        }
        vector<string> result;
        int cnt = 0;
        while(cnt < k){
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
            
        }
        // reverse(result.begin(), result.end());
        return result;
        
    }
};