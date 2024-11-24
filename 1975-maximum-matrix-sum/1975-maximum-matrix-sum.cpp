class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = std::numeric_limits<int>::max(), n = matrix.size(), negativeCount = 0;
        
        for (const auto& row : matrix){
            for (int val : row){
                totalSum += abs(val);
                if (val < 0){
                    ++negativeCount;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }
        
        // Adjust if the count of negative numbers is odd.
        if (negativeCount % 2)
            totalSum -= 2 * minAbsVal;
        
        return totalSum;
    }
};