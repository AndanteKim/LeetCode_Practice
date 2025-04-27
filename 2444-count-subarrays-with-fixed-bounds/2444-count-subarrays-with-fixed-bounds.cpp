class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // minPos, maxPos: the most recent positions of minK and maxK
        // left_bound: the most recent value outside the range [minK, maxK].
        long long ans = 0;
        int minPos = -1, maxPos = -1, leftBound = -1;

        // Iterate over nums, for each number at index i:
        for (int i = 0; i < (int)nums.size(); ++i){
            // If the number is outside the range [minK, maxK], update the most recent leftBound.
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;

            // If the number is minK or maxK, update the most recent position.
            if (nums[i] == minK) minPos = i;

            if (nums[i] == maxK) maxPos = i;

            // The number of valid subarrays equals the number of elements between leftBound and
            // the smaller of the two most recent positions.
            ans += max(0, min(minPos, maxPos) - leftBound);
        }

        return ans;
    }
};