class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        int lookfor;
        for (int i = 0; i < nums.size(); ++i){
            lookfor = target - nums[i];
            
            if (lookup.find(lookfor) != lookup.end()) return {i, lookup[lookfor]};
            lookup[nums[i]] = i; 
        }
        
        return {-1, -1};
    }
};