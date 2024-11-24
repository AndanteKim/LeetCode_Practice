class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minVal = std::numeric_limits<int>::max(), negativeCount = 0;
        
        for (const auto& row : matrix){
            for (int val : row){
                totalSum += abs(val);
                minVal = min(minVal, abs(val));
                negativeCount += (val >> 31) & 1;
            }
        }
        
        return (negativeCount & 1)? totalSum - (minVal << 1) : totalSum;
    }
};