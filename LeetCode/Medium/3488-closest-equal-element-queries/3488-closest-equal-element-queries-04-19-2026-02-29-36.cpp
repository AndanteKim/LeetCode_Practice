class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> pos;
        vector<int> left(n), right(n);
        for (int i = -n; i < n; ++i) {
            if (i >= 0) {
                left[i] = pos.contains(nums[i])? pos[nums[i]] : -n;
            }

            pos[nums[(i + n) % n]] = i;
        }

        pos.clear();

        for (int i = 2 * n - 1; i >= 0; --i) {
            if (i < n) {
                right[i] = pos.contains(nums[i])? pos[nums[i]] : 2 * n;
            }

            pos[nums[i % n]] = i;
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i];

            if (x - left[x] == n) ans[i] = -1;
            else ans[i] = min(x - left[x], right[x] - x);
        }

        return ans;
    }
};