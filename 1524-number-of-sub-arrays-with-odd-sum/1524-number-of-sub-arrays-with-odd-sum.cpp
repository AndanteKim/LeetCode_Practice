class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        constexpr int MOD = 1'000'000'007;
        int oddCnt = 0, evenCnt = 1;
        long long ans = 0, prefix = 0;

        for (int num : arr) {
            prefix += num;

            if (prefix % 2 == 0) {
                ans += oddCnt;
                ++evenCnt;
            }
            else {
                ans += evenCnt;
                ++oddCnt;
            }

            ans %= MOD;
        }

        return static_cast<int>(ans);
    }
};