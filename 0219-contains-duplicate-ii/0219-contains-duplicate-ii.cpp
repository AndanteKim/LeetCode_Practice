class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> k_lookup;
        
        for (int i = 0; i < nums.size(); ++i){
            if (k_lookup.find(nums[i]) != k_lookup.end() && abs(i - k_lookup[nums[i]]) <= k) return true;
            k_lookup[nums[i]] = i;
        }
        return false;
    
    }
};