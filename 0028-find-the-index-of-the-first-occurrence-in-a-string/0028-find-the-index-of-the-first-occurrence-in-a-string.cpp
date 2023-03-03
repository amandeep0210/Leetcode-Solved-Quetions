class Solution {
public:
    int strStr(string h, string n) {
        int ind = h.find(n);
        if(ind < h.size())return ind;
        return -1;
    }
};