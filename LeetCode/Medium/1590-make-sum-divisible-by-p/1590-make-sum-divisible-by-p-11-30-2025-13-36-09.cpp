class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), target = accumulate(nums.begin(), nums.end(), 0LL) % p;

        // Base case
        if (target == 0) return 0;

        // To handle the whole array is the answer
        // Track the prefix sum mod p
        unordered_map<int, int> modMap{{0, -1}};
        int currSum = 0, minLen = n;

        for (int i = 0; i < n; ++i) {
            currSum = (currSum + nums[i]) % p;

            // Calculate what we need to remove
            int needed = (currSum - target + p) % p;
            
            // If we've seen the needed remainder, we can consider this subarray
            if (modMap.find(needed) != modMap.end()) minLen = min(minLen, i - modMap[needed]);

            // Store the current remainder and index
            modMap[currSum] = i;
        }

        // Output the answer
        return minLen == n? -1 : minLen;
    }
};