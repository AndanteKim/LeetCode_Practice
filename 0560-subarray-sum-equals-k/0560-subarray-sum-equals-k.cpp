class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0, curr = 0;
        for (const int& num: nums){
            curr += num;
            ans += counts[curr - k];
            ++counts[curr];
        }
        return ans;
    }
};