typedef long long ll;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; ++i) groups[nums[i]].push_back(i);

        vector<ll> ans(n);
        for (const auto& [_, group] : groups) {
            ll sum = accumulate(group.begin(), group.end(), 0LL), prefix = 0;
            int sz = group.size();
            for (int i = 0; i < sz; ++i){
                int idx = group[i];
                ans[idx] = sum - 2 * prefix + idx * (2 * i - sz);
                prefix += idx;
            }
        }

        return ans;
    }
};