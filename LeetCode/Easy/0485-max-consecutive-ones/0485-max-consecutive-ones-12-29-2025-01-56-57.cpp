class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for (const int num : nums) {
            if (num) ++count;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }

        return max(ans, count);
    }
};