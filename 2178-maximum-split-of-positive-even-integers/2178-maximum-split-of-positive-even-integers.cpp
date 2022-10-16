class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum % 2 == 1) return ans;
        long long i = 2;
        long long temp = 0;
        while(temp+i <= finalSum){
            ans.push_back(i);
            temp += i;
            i = i+2;
        }
        if(temp < finalSum){
            ans[ans.size()-1] = ans[ans.size()-1] + finalSum-temp;
        }
        return ans;
    }
};