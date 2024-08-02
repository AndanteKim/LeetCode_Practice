class Solution {
private:
    int minSwapsHelper(vector<int>& data, int val){
        int n = data.size();
        vector<int> rightSuffixSum(n + 1);
        
        // Construct the suffix sum array for counting opposite values (val ^ 1)
        for (int i = n - 1; i >= 0; --i){
            rightSuffixSum[i] = rightSuffixSum[i + 1];
            if (data[i] == (val ^ 1))
                ++rightSuffixSum[i];
        }
        
        // Total zeros in the array if 'val' is 1 (or vice versa)
        int totalSwaps = rightSuffixSum[0];
        
        // Track current number of required swaps in the current segment
        int currSwap = 0;
        int minSwap = totalSwaps - rightSuffixSum[n - totalSwaps];
        
        // Iterate to find the minimum swaps by sliding
        // the potential block of grouped 'val'
        for (int i = 0; i < totalSwaps; ++i){
            if (data[i] == (val ^ 1))
                ++currSwap;
            int remaining = totalSwaps - i - 1;
            int requiredSwaps = ((i + 1) - currSwap) + (remaining - rightSuffixSum[n - remaining]);
            minSwap = min(minSwap, requiredSwaps);
        }
        
        return minSwap;
    }
    
public:
    int minSwaps(vector<int>& nums) {
        int op1 = minSwapsHelper(nums, 0);  // Groups 0's altogether
        int op2 = minSwapsHelper(nums, 1);  // Groups 1's altogether
        
        return min(op1, op2);
    }
};