class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];

        long long ans = 0, score, total;

        for (int j = 0; j < n; ++j){
            int lo = 0, hi = j, i = j;

            while (lo <= hi){
                int mid = lo + ((hi - lo) >> 1);
                int length = j - mid + 1;
                total = prefix[j + 1] - prefix[mid];
                score = total * length;
                if (score < k){
                    hi = mid - 1;
                    i = mid;
                }
                else
                    lo = mid + 1;
            }

            // If length 1 and score is greater than or equal to k, skip it.
            if (i == j && nums[j] >= k) continue;
            // else this will be valid because of binary search
            ans += j - i + 1;
        }

        return ans;
    }
};