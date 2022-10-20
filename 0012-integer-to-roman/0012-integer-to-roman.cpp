class Solution {
public:
    string intToRoman(int num) {
      vector<int> v1 ={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,2000,3000};
    vector<string> v2 ={"I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M","MM","MMM"};
    unordered_map<int, string> mp;
        for(int i = 0; i<v1.size(); i++){
            mp[v1[i]] = v2[i];
        }
        string result = "";
        vector<int> v;
        int n = log10(num)+1;
        int k = 0;
        while(num > 0){
            int rem = num %10;
            v.push_back(rem*pow(10,k));
            k++;
            num = num /10;
        }
        reverse(v.begin(), v.end());
        for(auto it : v){
            if(it != 0){
                result += mp[it];
            }
        }
       return result;
        
    }
};