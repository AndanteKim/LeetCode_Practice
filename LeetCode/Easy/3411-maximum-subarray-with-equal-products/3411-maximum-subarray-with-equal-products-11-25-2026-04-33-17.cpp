class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2, prod = 1, n = nums.size();
        int start = 0, end = 0;

        while (end < n) {
            while (gcd(prod, nums[end]) > 1) {
                prod /= nums[start++];
            }

            prod *= nums[end];
            ans = max(ans, end - start + 1);
            ++end;
        }

        return ans;
    }
};