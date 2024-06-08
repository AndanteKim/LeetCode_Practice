class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modSeen{{0, -1}};
        int prefixMod = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            prefixMod = (prefixMod + nums[i]) % k;
            
            if (modSeen.contains(prefixMod)){
                // Ensures that the size of subarray is at least two
                if (i - modSeen[prefixMod] > 1)
                    return true;
            }
            else
                // Mark the value of prefix_mod with the current index
                modSeen[prefixMod] = i;
        }
        
        return false;
    }
};