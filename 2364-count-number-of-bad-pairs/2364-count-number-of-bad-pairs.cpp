typedef long long ll;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < n; ++pos){
            ++diffCount[pos - nums[pos]];
        }

        ll ans = ((ll)(n - 1) * n) >> 1;

        for (const auto& [_, currCount] : diffCount){
            ll goodPairs = ((ll)(currCount - 1) * currCount) >> 1;
            ans -= goodPairs;
        }

        return ans;
    }
};