typedef long long ll;

class Solution {
private:
    int m, n;
    int f(vector<int>& nums2, ll x1, ll v){
        int left = 0, right = n - 1;

        while (left <= right){
            int mid = left + ((right - left) >> 1);

            if (x1 >= 0 && nums2[mid] * x1 <= v ||
                x1 < 0 && nums2[mid] * x1 > v)  left = mid + 1;
            else
                right = mid - 1;
        }

        return x1 >= 0? left : n - left;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        m = nums1.size(), n = nums2.size();
        vector<ll> candidates {(ll)nums1[0] * nums2[0], (ll)nums1.back() * nums2[0], (ll)nums1[0] * nums2.back(), (ll)nums1.back() * nums2.back()};
        long long left = *min_element(candidates.begin(), candidates.end()), right = *max_element(candidates.begin(), candidates.end());

        while (left <= right){
            ll mid = left + ((right - left) >> 1), count = 0;

            for (int num : nums1)
                count += f(nums2, num, mid);
            
            if (count < k) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};