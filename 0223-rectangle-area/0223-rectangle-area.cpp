class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = abs((ax1-ax2) * (ay1-ay2));
        int a2 = abs((bx1-bx2) * (by1-by2));
        int cx = 0;
        int cy = 0;
        if (ax2<=bx1 || ax1>=bx2 || ay1>=by2 || ay2<=by1 )return a1+a2;
        else{
            vector<int> c1,c2;
            c1 = {ax1,ax2,bx1,bx2};
            c2 = {ay1,ay2,by1,by2};
            sort(c1.begin(),c1.end());
            sort(c2.begin(),c2.end());
            cx = c1[2]-c1[1];
            cy = c2[2]-c2[1];
            return a1+a2 - (cx*cy);
            
        }
    
       
    }
};