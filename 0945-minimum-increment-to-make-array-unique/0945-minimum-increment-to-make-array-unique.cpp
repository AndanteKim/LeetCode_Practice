class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size(), maxVal = *max_element(nums.begin(), nums.end()), minIncrements = 0;
        
        // Create a freqCounts vector to store the frequency of each value
        // in nums
        vector<int> freqCounts(n + maxVal + 1);
        
        // Populate freqCounts vector with the frequency of each value in nums
        for (int num : nums)
            ++freqCounts[num];
        
        // Iterate over the freqCounts vector to make all values unique
        for (int i = 0; i < freqCounts.size(); ++i){
            if (freqCounts[i] <= 1)
                continue;
            
            // Determine excess occurrences, carry them over to the next value,
            // ensure single occurrence for current value, and update
            // minIncrements
            int duplicates = freqCounts[i] - 1;
            freqCounts[i + 1] += duplicates;
            freqCounts[i] = 1;
            minIncrements += duplicates;
        }
        
        return minIncrements;
    }
};