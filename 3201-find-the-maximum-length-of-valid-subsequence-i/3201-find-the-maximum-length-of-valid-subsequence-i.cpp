class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;

        for (const auto& pattern : vector<vector<int>> {{0, 0}, {1, 1}, {1, 0}, {0, 1}}){
            int count = 0;

            for (int num : nums){
                if (num % 2 == pattern[count % 2]) ++count;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};