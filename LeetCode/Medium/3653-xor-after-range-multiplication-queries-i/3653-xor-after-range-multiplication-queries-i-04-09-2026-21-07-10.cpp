class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), MOD = 1'000'000'007;

        for (const auto& query : queries) {
            int v = query[3];
            for (int i = query[0]; i <= query[1]; i += query[2]){
                nums[i] = ((long long)nums[i] * v) % MOD;
            }
        }

        int ans = 0;
        for (int num : nums) ans ^= num;

        return ans;
    }
};