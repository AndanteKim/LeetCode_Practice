class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0, mod = 1'000'000'007;
        unordered_map<int, int> numsCnt, numsPartialCnt;

        for (int num : nums) ++numsCnt[num];

        int target, leftCnt, rightCnt;
        for (int num : nums) {
            target = num * 2;
            leftCnt = numsPartialCnt[target];
            ++numsPartialCnt[num];
            rightCnt = numsCnt[target] - numsPartialCnt[target];
            ans = static_cast<int>((ans + (long long)leftCnt * rightCnt) % mod);
        }

        return ans;
    }
};