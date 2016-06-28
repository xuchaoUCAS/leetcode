class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        int len = m + n;
        while(m || n){
            if(m <= 0){
                nums1[len - 1] = nums2[n - 1];
                --n;
            }
            else if(n <= 0){
                nums1[len - 1] = nums1[m - 1];
                --m;
            }
            else if(nums1[m - 1] > nums2[n - 1] || n <= 0){
                nums1[len - 1] = nums1[m - 1];
                --m;
            }
            else{
                nums1[len - 1] = nums2[n - 1];
                --n;
            }
            --len;
        }
    }
};