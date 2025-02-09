class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); ++pos){
            int diff = pos - nums[pos];

            // Count of previous positions with the same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs - good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            ++diffCount[diff];
        }

        return badPairs;
    }
};