class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        // Find the maximum value in the input array
        int maxVal = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> freq(maxVal + 1), ans(n - k + 1);
        int distinctCount = 0;
        
        // Create a frequency array based on the maximum value in the input
        for (int pos = 0; pos < n; ++pos){
            // Add new number to window
            ++freq[nums[pos]];
            if (freq[nums[pos]] == 1) ++distinctCount;

            // Remove number from previous window
            if (pos >= k){
                --freq[nums[pos - k]];
                if (freq[nums[pos - k]] == 0) --distinctCount;
            }
            
            // Store result when window is complete
            if (pos + 1 >= k)
                ans[pos + 1 - k] = distinctCount; 
        }

        return ans;
    }
};