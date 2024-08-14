class Solution {
private:
    // Count number of pairs with distance <= m
    int countPairs(const vector<int>& nums, const vector<int>& prefixCount, unordered_map<int, int>& valueCount, const int maxDist){
        int count = 0, n = nums.size(), index = 0;
        
        while (index < n){
            int currVal = nums[index];
            int valueCountForCurrent = valueCount[currVal];
            
            // Calculate pairs involving current value with distance <= maxDist
            int pairsWithLargerValue = prefixCount[currVal + maxDist] - prefixCount[currVal];
            int pairsWithSameValue = (valueCountForCurrent * (valueCountForCurrent - 1)) >> 1;
            
            count += pairsWithLargerValue * valueCountForCurrent + pairsWithSameValue;
            
            // Skip duplicate values
            while (index + 1 < n && nums[index] == nums[index + 1])
                ++index;
            ++index;
        }
        
        return count;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Largest element in the sorted array
        int maxElem = nums.back();
        
        // Maximum possible distance
        int maxPossibleDist = maxElem * 2;
        
        // Initialize arrays for prefix counts
        vector<int> prefixCount(maxPossibleDist);
        unordered_map<int, int> valueCount;
        
        // Populate the prefixCount array
        int index = 0;
        for (int val = 0; val < maxPossibleDist; ++val){
            while (index < n && nums[index] <= val)
                ++index;
            
            prefixCount[val] = index;
        }
        
        // Populate the valueCount array
        for (int val : nums)
            ++valueCount[val];
        
        // Binary search for the k-th smallest distance
        int left = 0, right = maxElem;
        while (left < right){
            int mid = (left + right) >> 1;
            
            // Count pairs with distance <= mid
            int count = countPairs(nums, prefixCount, valueCount, mid);
            
            // Adjust binary search bounds based on count
            if (count >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};