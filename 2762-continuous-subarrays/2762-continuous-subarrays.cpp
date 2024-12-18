typedef long long ll;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), left = 0;
        ll ans = 0;     // Total count of valid subarrays
        
        // Min and max heaps storing indices, sorted by nums[index] values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap, maxHeap;
        
        for (int right = 0; right < n; ++right){
            // Add current index to both heaps
            minHeap.push({nums[right], right});
            maxHeap.push({-nums[right], right});
            
            // While window violates |nums[i] - nums[j]| <= 2 condition
            // Shrink window from left and remove outdated indices
            while (left < right && -maxHeap.top().first - minHeap.top().first > 2){
                ++left;
                
                // Remove indices that are now outside window
                while (minHeap.top().second < left)
                    minHeap.pop();
                
                while (maxHeap.top().second < left)
                    maxHeap.pop();
            }
            
            // Add count of all valid subarrays ending at right
            ans += right - left + 1;
        }
        
        return ans;
    }
};