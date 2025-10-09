class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size(), n = skill.size();
        vector<long long> ans(n + 1);

        for (int j = 0; j < m; ++j){
            for (int i = 0; i < n; ++i) ans[i + 1] = max(ans[i + 1], ans[i]) + (long long)skill[i] * mana[j];

            for (int i = n - 1; i >= 0; --i) ans[i] = ans[i + 1] - (long long)skill[i] * mana[j];
        }

        return ans.back();
    }
};