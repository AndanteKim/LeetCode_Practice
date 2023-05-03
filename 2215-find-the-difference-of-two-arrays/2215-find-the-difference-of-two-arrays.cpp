class Solution {
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> onlyInNums1, existsInNums2;
        for (int num : nums2) existsInNums2.insert(num);
        
        for (int num : nums1) {
            if (existsInNums2.find(num) == existsInNums2.end()){
                onlyInNums1.insert(num);
            }
        }
        
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
}; 