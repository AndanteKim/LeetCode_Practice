class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int sum = 0, squaredSum = 0;

        for (int num : nums) {
            sum += num;
            squaredSum += num * num;
        }

        int sum2 = sum - (n * (n - 1) >> 1), squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6;
        int x1 = (sum2 - (int)sqrt(2 * squaredSum2 - sum2 * sum2)) >> 1;
        int x2 = (sum2 + (int)sqrt(2 * squaredSum2 - sum2 * sum2)) >> 1;

        return vector<int>{x1, x2};
    }
};