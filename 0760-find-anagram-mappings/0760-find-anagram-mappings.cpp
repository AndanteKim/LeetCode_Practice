class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        const int bitsToShift = 7;
        const int numsToGetLastBits = (1 << bitsToShift) - 1;
        
        for (int i = 0; i < nums1.size(); ++i){
            nums1[i] = (nums1[i] << bitsToShift) + i;
            nums2[i] = (nums2[i] << bitsToShift) + i;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> mappings(nums1.size(), 0);
        
        for (int i = 0; i < nums1.size(); ++i){
            mappings[nums1[i] & numsToGetLastBits] = (nums2[i] & numsToGetLastBits);
        }
        
        return mappings;
    }
};