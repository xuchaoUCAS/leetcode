class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int l = 1, r = x;
        while(l < r){
            int mid = (l + r) / 2;
            if(mid > x / mid)
                r = mid - 1;
            else{
                if(mid + 1 > x / (mid + 1))
                    return mid;
                l = mid + 1;
            }
        }
        return l;
    }
};