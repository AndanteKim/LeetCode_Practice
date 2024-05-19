class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> netChange(n);
        long long nodeSum = 0;
        for (int i = 0; i < n; ++i){
            netChange[i] = (nums[i] ^ k) - nums[i];
            nodeSum += 1LL * nums[i];
        }
        sort(netChange.begin(), netChange.end(), greater<int>());
        
        for (int i = 0; i < n; i += 2){
            // If netChange contains odd number of elements, break the loop
            if (i + 1 == n) break;
            long long pairSum = netChange[i] + netChange[i + 1];
            
            // If pair of sum is positive, include in nodeSum
            if (pairSum > 0) nodeSum += pairSum;
        }
        
        return nodeSum;
    }
};