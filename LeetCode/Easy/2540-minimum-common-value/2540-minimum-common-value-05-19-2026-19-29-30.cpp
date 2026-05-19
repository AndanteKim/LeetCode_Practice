class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int first = 0, second = 0;

        for (;first < nums1.size() && second < nums2.size();) {
            if (nums1[first] > nums2[second]) ++second;
            else if (nums1[first] < nums2[second]) ++first;
            else return nums1[first];
        }

        return -1;
    }
};