class Solution {
public:
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
       int area = (ax1-ax2)*(ay1-ay2)+ (bx1-bx2)*(by1-by2);
        int wid =min(ax2,bx2) -max(ax1,bx1);
        int height = min(ay2,by2) -max(ay1,by1);
        int overlap = height*wid;
        if(height>0 && wid>0){
            area -= overlap;
        }
        return area;
    }
};