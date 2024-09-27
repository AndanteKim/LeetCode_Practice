class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Base case
        if (prices.size() <= 1) return 0;
        
        int n = prices.size();
        int leftMin = prices[0], rightMax = prices.back();
        
        // Pad the right DP array with an additional zero for the convenience
        vector<int> leftProfit(n), rightProfit(n + 1);
        
        // Construct the bidirectional DP array
        for (int left = 1; left < n; ++left){
            leftProfit[left] = max(leftProfit[left - 1], prices[left] - leftMin);
            leftMin = min(leftMin, prices[left]);
            
            int right = n - 1 - left;
            rightProfit[right] = max(rightProfit[right + 1], rightMax - prices[right]);
            rightMax = max(rightMax, prices[right]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < n; ++i)
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i + 1]);
        
        return maxProfit;
    }
};