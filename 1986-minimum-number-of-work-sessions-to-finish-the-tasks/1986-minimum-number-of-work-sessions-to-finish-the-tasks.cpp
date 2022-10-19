class Solution {
public:
    
    // using binary search
    bool isValid(int &mid, int & sessionTime, vector<int>& tasks, vector<int>&v, int ind){
        if(ind >= tasks.size())return true; // it means that we have assignes all the tasks 
        for(int i = 0; i<v.size(); i++){
            if(v[i] + tasks[ind] <= sessionTime){
                v[i] += tasks[ind];
                if(isValid(mid, sessionTime, tasks, v, ind+1))return true;
                v[i] -= tasks[ind];
                if(v[i] == 0)break; 
                // here we are breaking beacuse if it is giving zeros than it means next remaining cells will also give false;
            }
        }
        return false;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        int s = 1;
        int e = tasks.size();
        int ans = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            vector<int> v(mid, 0);
            if(isValid(mid, sessionTime, tasks, v, 0)){
                e = mid - 1;
                ans = mid;
            }
            else{
                s = mid +  1;
            }
        }
        return ans;
    }
};