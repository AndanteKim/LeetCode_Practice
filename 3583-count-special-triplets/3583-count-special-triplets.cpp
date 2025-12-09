class Solution {
private:
    pair<int, int> upperBound(vector<int>& arr, int i) {
        int mid, left = 0, right = arr.size() - 1;

        while (left < right) {
            mid = left + ((right - left + 1) >> 1);
            if (i >= arr[mid]) left = mid;
            else right = mid - 1;
        }

        return pair<int, int>{left + 1, arr.size() - left - 1};
    }

public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1'000'000'007, ans = 0, n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) pos[nums[i]].push_back(i);

        int target;
        for (int i = 1; i < n - 1; ++i) {
            target = nums[i] * 2;
            if (pos.count(target) && (pos[target].size() > 1) && (pos[target][0] < i)) {
                auto [l, r] = upperBound(pos[target], i);

                if (nums[i] == 0)
                    --l;
                ans = static_cast<int>((ans + (long long)l * r) % mod);
            }
        }

        return ans;
    }
};