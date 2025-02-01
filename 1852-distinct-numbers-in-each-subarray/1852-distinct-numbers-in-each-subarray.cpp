class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);

        // Map to store number -> frequency count
        unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i){
            ++freq[nums[i]];
        }

        ans[0] = freq.size();

        // Slide window and update counts
        for (int pos = k; pos < n; ++pos){
            // Remove the leftmost element of previous window
            int left = nums[pos - k];
            --freq[left];
            if (freq[left] == 0) freq.erase(left);

            // Add rightmost element of current window
            int right = nums[pos];
            ++freq[right];

            // Store distinct count for current window
            ans[pos - k + 1] = freq.size();
        }

        return ans;
    }
};