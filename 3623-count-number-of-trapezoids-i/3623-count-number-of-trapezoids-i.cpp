class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1'000'000'007;
        unordered_map<int, int> pointNums;
        for (const auto& point : points) ++pointNums[point[1]];

        int ans = 0, totalSum = 0;

        for (const auto& [_, count] : pointNums) {
            long long edge = (long long)count * (count - 1) >> 1;
            ans = (ans + edge * totalSum) % mod;
            totalSum = (totalSum + edge) % mod;
        }

        return ans;
    }
};