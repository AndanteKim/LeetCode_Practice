class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int k, int n1Start, int n1End, int n2Start, int n2End){
        if (n1Start > n1End)
            return nums2[k - n1Start];
        if (n2Start > n2End)
            return nums1[k - n2Start];
        
        int n1Mid = (n1Start + n1End) >> 1, n2Mid = (n2Start + n2End) >> 1;
        int n1Val = nums1[n1Mid], n2Val = nums2[n2Mid];
        
        if (n1Mid + n2Mid < k){
            if (n1Val > n2Val)
                return solve(nums1, nums2, k, n1Start, n1End, n2Mid + 1, n2End);
            else
                return solve(nums1, nums2, k, n1Mid + 1, n1End, n2Start, n2End);
        }
        else{
            if (n1Val > n2Val)
                return solve(nums1, nums2, k, n1Start, n1Mid - 1, n2Start, n2End);
            else
                return solve(nums1, nums2, k, n1Start, n1End, n2Start, n2Mid - 1);
        }
        
        return -1;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        
        if (n % 2)
            return solve(nums1, nums2, n / 2, 0, n1 - 1, 0, n2 - 1);
        else
            return (double)(solve(nums1, nums2, n / 2 - 1, 0, n1 - 1, 0, n2 - 1) + solve(nums1, nums2, n / 2, 0, n1 - 1, 0, n2 - 1)) / 2;
    }
};