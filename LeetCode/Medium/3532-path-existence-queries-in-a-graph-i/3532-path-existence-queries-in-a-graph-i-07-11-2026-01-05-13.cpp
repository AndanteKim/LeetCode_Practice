class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> rights;
        
        for (int i = 1; i < n; ++i) {
            if (abs(nums[i] - nums[i - 1]) > maxDiff) rights.push_back(i - 1);
        }

        rights.push_back(n - 1);
        int q = queries.size();
        vector<bool> ans(q, false);

        for (int i = 0; i < q; ++i) {
            int u = queries[i][0], v = queries[i][1];
            int x = lower_bound(rights.begin(), rights.end(), u) - rights.begin(), y = lower_bound(rights.begin(), rights.end(), v) - rights.begin();
            ans[i] = (x == y);
        }

        return ans;
    }
};