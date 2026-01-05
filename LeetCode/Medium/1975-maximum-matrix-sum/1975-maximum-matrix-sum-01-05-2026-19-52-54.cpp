class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int minAbsVal = std::numeric_limits<int>::max(), negativeCount = 0;

        for (const auto& row : matrix) {
            for (const int val : row) {
                ans += abs(val);
                if (val < 0) ++negativeCount;
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2) ans -= 2 * minAbsVal; 

        return ans;
    }
};