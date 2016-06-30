class Solution {
private:
    int getkth_(int nums1[], int len1, int nums2[], int len2, int k){ 
       if (len2 == 0)
           return nums1[k-1];
       if(len1 == 0)
           return nums2[k-1];
       if(k==1)
           return min(nums1[0], nums2[0]);
       int i = min(len1,k/2), j = min(len2,k/2);
       if(nums1[i-1] < nums2[j-1])
           return getkth_(nums1+i, len1-i, nums2, len2, k-i);
       else
           return getkth_(nums1, len1, nums2+j, len2-j, k-j);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int k = (len1 + len2 + 1) >> 1;
        if((len1 + len2) & 1)
            return getkth_(&nums1[0], len1 ,&nums2[0], len2, k); 
        else {
            return (getkth_(&nums1[0], len1 ,&nums2[0], len2, k) + getkth_(&nums1[0], len1 ,&nums2[0], len2, k+1)) / 2.0;
        }   
    }
};
