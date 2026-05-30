class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = std::numeric_limits<int>::max();

        for (int num : nums) {
            int currSum = 0;

            while (num > 0) {
                currSum += num % 10;
                num /= 10;
            }

            ans = min(ans, currSum);
        }

        return ans;
    }
};