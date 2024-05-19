class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sumVal = 0;
        int count = 0, positiveMin = (1 << 30), negativeMax = -1 * (1 << 30);;
        
        for (int nodeVal:nums){
            int operated = nodeVal ^ k;
            sumVal += nodeVal;
            
            int netChange = operated - nodeVal;
            
            if (netChange > 0){
                ++count;
                positiveMin = min(positiveMin, netChange);
                sumVal += netChange;
            }
            else
                negativeMax = max(negativeMax, netChange);
        }
        
        // If the number of positive net_change is even, return sumVal
        if (count % 2 == 0)
            return sumVal;
        
        // Otherwise return the maximum of both discussed cases.
        return max(sumVal - positiveMin, sumVal + negativeMax);
    }
};