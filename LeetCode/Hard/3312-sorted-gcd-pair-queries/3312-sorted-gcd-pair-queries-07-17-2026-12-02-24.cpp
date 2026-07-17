class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);

        for (int num : nums) ++cnt[num];

        for (int i = 1; i <= m; ++i) {
            for (int j = i * 2; j <= m; j += i)
                cnt[i] += cnt[j];
        }

        for (int i = 1; i <= m; ++i) cnt[i] = (cnt[i] * (cnt[i] - 1)) >> 1;

        for (int i = m; i >= 1; --i) {
            for (int j = i * 2; j <= m; j += i) 
                cnt[i] -= cnt[j];
        }

        for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            int pos = lower_bound(cnt.begin(), cnt.end(), queries[i] + 1) - cnt.begin();
            ans[i] = pos;
        }
        
        return ans;
    }
};