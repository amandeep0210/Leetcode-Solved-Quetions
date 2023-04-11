class Solution {
public:
    string removeStars(string s) {
        string t = "";
        for(auto it : s){
            if(t.size() == 0){
                t.push_back(it);
            }
            else{
                if(it =='*')t.pop_back();
                else t.push_back(it);
            }
        }
        return t;
    }
};