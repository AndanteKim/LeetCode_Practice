class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> tags(n);

        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) tags[i] = tags[i - 1] + 1;
            else tags[i] = tags[i - 1];
        }

        int q = queries.size();
        vector<bool> ans(q);

        for (int i = 0; i < q; ++i) {
            ans[i] = (tags[queries[i][0]] == tags[queries[i][1]]);
        }
        
        return ans;
    }
};