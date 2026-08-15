class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int curr = 0, n = nums.size();
        bool nonZero = false;

        for (int num : nums) {
            curr ^= num;
            nonZero |= (num > 0);
        }

        if (curr > 0) return n;

        return nonZero? n - 1 : 0;
    }
};