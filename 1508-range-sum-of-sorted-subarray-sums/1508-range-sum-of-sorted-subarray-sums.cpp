typedef long long ll;

class Solution {
private:
    int mod = 1'000'000'007;
    // Helper function to count subarrays with sum <= target and their total sum.
    pair<int, ll> countAndSum(vector<int>& nums, int n, int target){
        ll currSum = 0, windowSum = 0, totalSum = 0;
        int count = 0;
        
        for (int j = 0, i = 0; j < n; ++j){
            currSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            
            while (currSum > target){
                windowSum -= currSum;
                currSum -= nums[i++];
            }
            
            count += (j - i + 1);
            totalSum += windowSum;
        }
        
        return make_pair(count, totalSum);
    }
    
    // Helper function to find the sum of the first k smallest subarray sums
    ll sumOfFirstK(vector<int>& nums, int n, int k){
        int left = *min_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0LL);
        
        while (left <= right){
            ll mid = (left + right) >> 1;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        auto [count, totalSum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return totalSum - (left * (count - k));
    }
    
    
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ll ans = (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) % mod;
        return (ans + mod) % mod;
    }
};