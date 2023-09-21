class Solution {
private:
    int i = 0, j = 0, m, n;
    // Get the smaller value between nums1[i] and nums2[j] and move the pointer forward
    int getMin(vector<int>& nums1, vector<int>& nums2){
        if (i < m && j < n)
            return nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        else if (i < m)
            return nums1[i++];
        else if (j < n)
            return nums2[j++];
        return -1;
    }
    
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        this -> m = nums1.size(), this -> n = nums2.size();
        
        if ((m + n) % 2 == 0){
            for (int i = 0; i < (m + n) / 2 - 1; ++i){
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        }
        else{
            for (int i = 0; i < (m + n) / 2; ++i){
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }
        
        return -1;
    }
};