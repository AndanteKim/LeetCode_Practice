class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        vector<vector<int>> ans;

        while (ptr1 < n1 && ptr2 < n2){
            // If the id is same, add the values and insert to the result.
            // increment both pointeres.
            if (nums1[ptr1][0] == nums2[ptr2][0]){
                ans.push_back(
                    {nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]}
                );
                ++ptr1;
                ++ptr2;
            }
            else if (nums1[ptr1][0] < nums2[ptr2][0]){
                // If the id in nums1 is smaller, add it to result and increment the pointer
                ans.push_back(nums1[ptr1++]);
            }
            else{
                // If the id in nums2 is smaller, add it to result and increment the pointer
                ans.push_back(nums2[ptr2++]);
            }
        }

        // If pairs are remaining in the nums1, then add them to the result.
        while (ptr1 < n1){
           ans.push_back(nums1[ptr1++]);
        }

        // If pairs are remaining in the nums2, then add them to the result.
        while (ptr2 < n2){
            ans.push_back(nums2[ptr2++]);
        }

        return ans;
    }
};