class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, curr = 0;
        int n = nums.size(), left = 0, length;

        for (int right = 0; right < n; ++right){
            curr += nums[right];

            while (left <= right && curr * (right - left + 1) >= k){
                curr -= nums[left++];
            }

            length = right - left + 1;
            ans += length;
        }

        return ans;
    }
};