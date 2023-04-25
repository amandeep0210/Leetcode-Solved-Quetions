class SmallestInfiniteSet {
public:
    int mini = 1;
    unordered_map<int,int> mp;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        mp[mini]--;
        int res = mini;
        while(mp[mini] < 0)mini++;
        return  res;
        
    }
    
    void addBack(int num) {
        if(mp[num] < 0){
            mp[num]++;
         if(num < mini)mini = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */