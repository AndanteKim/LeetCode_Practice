class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int u = 1, m = *max_element(nums.begin(), nums.end());

        while (u <= m) u <<= 1;

        int n = nums.size();
        vector<bool> s(u, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) s[nums[i] ^ nums[j]] = true;
        }

        vector<bool> t(u, false);
        for (int x = 0; x < u; ++x) {
            if (!s[x]) continue;

            for (int v : nums)
                t[x ^ v] = true;
        }

        return accumulate(t.begin(), t.end(), 0);
    }
};