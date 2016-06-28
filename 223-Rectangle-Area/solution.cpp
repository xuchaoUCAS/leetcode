class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (D - B) * (C - A);
        int areaB = (H - F) * (G - E);
        
        int left = max(A, E);
        int right = min(C, G);
        int bottom = max(B, F);
        int top = min(D, H);
        
        int over = 0;
        if(right > left && top > bottom){
            over = (right - left) * (top - bottom);
        }
        return areaA + areaB - over;
    }
};