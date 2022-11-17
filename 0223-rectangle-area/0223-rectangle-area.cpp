class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        
        int area1 = calculateArea(ax1, ax2, ay1, ay2);
        int area2 = calculateArea(bx1, bx2, by1, by2);
        
        int commonArea = calculateOverlap(ax1, ax2, bx1, bx2) * calculateOverlap(ay1, ay2, by1, by2);
        
        
        return area1 + area2 - commonArea;
        
        
    }
    
    int calculateArea(int a1, int a2, int b1, int b2)
    {
        return (b2-b1) * (a2-a1);
    }
    
    int calculateOverlap(int a1, int a2, int b1, int b2)
    {
        int overlap = min(a2, b2) - max(a1, b1);
        return overlap > 0 ? overlap : 0;
    }
};