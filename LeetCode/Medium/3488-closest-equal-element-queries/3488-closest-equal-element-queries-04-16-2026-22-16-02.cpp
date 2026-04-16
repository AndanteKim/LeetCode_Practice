class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < n; ++i) indices[nums[i]].push_back(i);

        for (auto& [_, elems] : indices) {
            int x = elems[0];
            elems.insert(elems.begin(), elems.back() - n);
            elems.push_back(x + n);
        }

        int qSize = queries.size();
        vector<int> ans(qSize, -1);
        for (int i = 0; i < qSize; ++i) {
            int query = queries[i], x = nums[query];

            if (indices[x].size() == 3) continue;
            int pos = lower_bound(indices[x].begin(), indices[x].end(), query) - indices[x].begin();
            ans[i] = min(abs(indices[x][pos - 1] - indices[x][pos]), abs(indices[x][pos] - indices[x][pos + 1]));
        }

        return ans;
    }
};