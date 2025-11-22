class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans += min(num % 3, 3 - (num % 3));
        }

        return ans;
    }
};