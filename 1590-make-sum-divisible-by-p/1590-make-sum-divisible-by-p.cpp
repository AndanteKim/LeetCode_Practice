class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), totalSum = 0;
        
        // Step 1: Calculate total sum and target remainder
        for (int num : nums)
            totalSum = (totalSum + num) % p;
        
        int target = totalSum % p;
        // If the target is divisibly by p
        if (target == 0)
            return 0;
        
        // Step 2: Use a hash map to track prefix sum mod p
        int currSum = 0, minLen = n;
        // To handle the case where the whole prefix is the answer
        unordered_map<int, int> modMap{{0, -1}};
        
        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i){
            currSum = (currSum + nums[i]) % p;
            
            // Calculate what we need to remove
            int needed = (currSum - target + p) % p;
            
            // If we've seen the needed remainder, we can consider this subarray
            if (modMap.count(needed))
                minLen = min(minLen, i - modMap[needed]);
            
            // Store the current remainder and index
            modMap[currSum] = i;
        }
        
        
        // Step 4: Return result
        return minLen == n? -1 : minLen;
    }
};