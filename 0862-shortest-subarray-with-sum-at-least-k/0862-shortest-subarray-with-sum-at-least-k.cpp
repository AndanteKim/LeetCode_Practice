class Solution {
private:
    // Binary search to find the largest index where cumulative sum is <= target
    int findCandidateIndex(const vector<pair<long long, int>>& monotonicStack, long long target){
        int left = 0, right = monotonicStack.size() - 1;
        
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            
            if (monotonicStack[mid].first <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return right;
    }
    
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = std::numeric_limits<int>::max();
        long long cumulativeSum = 0LL;
        // Stack-like vector to store cumulative sums and their indices
        vector<pair<long long, int>> monotonicStack{{0LL, -1}};
        
        for (int i = 0; i < n; ++i){
            // Update cumulative sum
            cumulativeSum += nums[i];
            
            // Remove entries from stack that are larger than current cumulative sum
            while (!monotonicStack.empty() && cumulativeSum <= monotonicStack.back().first){
                monotonicStack.pop_back();
            }
            
            // Add current cumulative sum and index to stack
            monotonicStack.push_back({cumulativeSum, i});
            int candidateIndex = findCandidateIndex(monotonicStack, cumulativeSum - k);
            
            // If a valid candidate is found, update the shortest subarray length
            if (candidateIndex != -1)
                ans = min(ans, i - monotonicStack[candidateIndex].second);
        }
        
        // Return -1 if no valid subarray found
        return (ans == std::numeric_limits<int>::max())? -1 : ans;
    }
};