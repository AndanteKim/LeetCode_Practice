class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        for (const auto& num : nums){
            curr += num % 2;
            ans += counts[curr - k];
            ++counts[curr];
        }
        return ans;
    }
};