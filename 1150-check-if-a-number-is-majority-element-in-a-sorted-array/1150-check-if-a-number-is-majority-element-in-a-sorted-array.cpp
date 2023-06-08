class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        double half = nums.size() / 2;
        for (int num : nums) ++freq[num];
        
        return (freq[target] > half)? true : false;
    }
};