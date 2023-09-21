class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m;
        while (left <= right){
            int partA = (left + right) >> 1;
            int partB = ((m + n + 1) >> 1) - partA;
            
            int maxLeftA = partA == 0? INT_MIN : nums1[partA - 1];
            int minRightA = partA == m? INT_MAX : nums1[partA];
            int maxLeftB = partB == 0? INT_MIN : nums2[partB - 1];
            int minRightB = partB == n? INT_MAX : nums2[partB];
            
            if (maxLeftA <= minRightB && maxLeftB <= minRightA){
                if ((m + n) % 2 == 0)
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                else
                    return max(maxLeftA, maxLeftB);
            }
            else if (maxLeftA > minRightB)
                right = partA - 1;
            else
                left = partA + 1;
        }
        
        return -1;
    }
};